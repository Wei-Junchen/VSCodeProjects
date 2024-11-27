#include <iostream>
#include <Windows.h>
#include <string>
#include <thread>

using namespace std;

// 模拟键盘输入函数
void simulateTextInput(const string& text) {
    INPUT inputs[2] = {};
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_DELETE; // 按下 DELETE 键
    inputs[1] = inputs[0];
    inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 松开 DELETE 键
    SendInput(2, inputs, sizeof(INPUT));
    for (char c : text) {
        // 构造按键事件
        INPUT input = {0};
        input.type = INPUT_KEYBOARD;
        if(c=='\n'){
            input.type=INPUT_KEYBOARD;
            input.ki.wVk=VK_RETURN;
            SendInput(1,&input,sizeof(INPUT));
            input.ki.dwFlags=KEYEVENTF_KEYUP;
            SendInput(1,&input,sizeof(INPUT));
        }
        // 判断是否是大写字母
        if (isupper(c)) {
            // 模拟按下 Shift 键
            INPUT shiftPress = {0};
            shiftPress.type = INPUT_KEYBOARD;
            shiftPress.ki.wVk = VK_SHIFT;
            SendInput(1, &shiftPress, sizeof(INPUT));
        }

        // 模拟按下当前字符的按键
        input.ki.wVk = 0; // 清空虚拟键码
        input.ki.wScan = c; // 设置扫描码
        input.ki.dwFlags = KEYEVENTF_UNICODE; // 标记为 Unicode 输入
        SendInput(1, &input, sizeof(INPUT));

        // 模拟释放当前字符的按键
        input.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));

        // 释放 Shift 键（如果之前按下了）
        if (isupper(c)) {
            INPUT shiftRelease = {0};
            shiftRelease.type = INPUT_KEYBOARD;
            shiftRelease.ki.wVk = VK_SHIFT;
            shiftRelease.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &shiftRelease, sizeof(INPUT));
        }

        // 延迟以模拟人类输入速度
        Sleep(25);
    }
}

int main() {
    string inputText;

    // 获取用户输入文本
    cout << "Input text with '#' end:\n";
    getline(cin, inputText, '#'); // 读取到 # 为止
    cout << "\nDone , press P to input\n";

    // 检测按键事件
    while (true) {
        if (GetAsyncKeyState('P') & 0x8000) { // 检测 P 键是否按下
            cout << "detected P input,start to input,you have 3s to put your cursor to input line\n";
            Sleep(3000);
            simulateTextInput(inputText);
            break;
        }
        Sleep(100); // 避免占用过多 CPU
    }

    cout << "Done!\n";
    system("pause");
    return 0;
}