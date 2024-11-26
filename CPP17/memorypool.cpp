#include <iostream>
#include <vector>
#include <memory>

class MemoryPool {
public:
    // 构造一个大小为 `total_size` 的内存池
    explicit MemoryPool(std::size_t total_size) : pool{std::make_unique<char[]>(total_size)}, pool_size{total_size}, used{0} {}

    // 从内存池中分配一块指定大小的内存
    void* allocate(std::size_t size) {
        if (used + size > pool_size) {
            throw std::bad_alloc();  // 如果内存池没有足够空间，抛出异常
        }
        void* ptr = pool.get() + used;
        used += size;
        return ptr;
    }

private:
    std::unique_ptr<char[]> pool;  // 内存池
    std::size_t pool_size;         // 总内存池大小
    std::ptrdiff_t used;              // 已使用的内存
};

// 数据群结构
class DataGroup {
public:
    DataGroup(MemoryPool& pool, std::size_t size) {
        // 从内存池中分配内存
        data = static_cast<int*>(pool.allocate(size * sizeof(int)));
        size_ = size;
    }

    int& operator[](std::size_t index) {
        return data[index];
    }

    std::size_t size() const {
        return size_;
    }

private:
    int* data;  // 数据群的指针
    std::size_t size_;  // 数据群的大小
};

// 数据结构，包含多个离散的数据群
class DiscreteDataStructure {
public:
    DiscreteDataStructure(std::size_t num_groups, std::size_t group_size, MemoryPool& pool)
        : group_count(num_groups) {
        for (std::size_t i = 0; i < num_groups; ++i) {
            groups.push_back(std::make_unique<DataGroup>(pool, group_size));
        }
    }

    DataGroup& operator[](std::size_t index) {
        return *groups[index];
    }

    std::size_t group_count;  // 数据群数量

private:
    std::vector<std::unique_ptr<DataGroup>> groups;  // 离散的数据群
};

int main() {
    // 创建内存池，大小为 1024 字节
    MemoryPool pool(1024);

    // 创建包含 5 个数据群，每个数据群大小为 10 的数据结构
    DiscreteDataStructure data(5, 10, pool);

    // 设置并获取数据群中的数据
    data[0][0] = 100;
    data[1][5] = 200;
    data[2][9] = 300;

    std::cout << "Group 0, Element 0: " << data[0][0] << std::endl;
    std::cout << "Group 1, Element 5: " << data[1][5] << std::endl;
    std::cout << "Group 2, Element 9: " << data[2][9] << std::endl;

    return 0;
}
