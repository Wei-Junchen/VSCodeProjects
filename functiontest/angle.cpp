#include <iostream>
#include <cmath>

float normalizeAngle(float angle)   
{
    angle = std::fmod(angle, 360.0f);  // 规范化到 [0, 360)
    if (angle < 0) angle += 360.0f;  // 处理负角度
    if (angle >= 180) angle -= 360.0f;  // 调整到 [-180, 180)
    return angle;
}


/**
* @brief 计算两个角度的差角，永远是劣弧，最短路径 ,必须规范顺时针为负，逆时针为正
 * 
 * @return float 输出结果 angle1 减去 angle2
 */

float differangle_caculate(float angle1, float angle2)
{
	
	float normalized1 = normalizeAngle(angle1);
    float normalized2 = normalizeAngle(angle2);
    float difference = normalized1 - normalized2;
	
	if (difference > 180) difference -= 360;
    else if (difference < -180) difference += 360;

    return difference;
	
}

int main()
{
    std::cout<<differangle_caculate(270, -45)<<std::endl;
    return 0;
}