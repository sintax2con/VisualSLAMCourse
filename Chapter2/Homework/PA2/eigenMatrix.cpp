#include <iostream>
using namespace std;
#include <ctime>
// Eigen 部分
#include <Eigen/Core>
// 稠密矩阵的代数运算（逆，特征值等）
#include <Eigen/Dense>

#define MATRIX_SIZE 50

/****************************
* 本程序演示了 Eigen 基本类型的使用
****************************/

int main(int argc, char **argv)
{
    // 1. 熟悉 Eigen 矩阵运算
    clock_t time_stt; // 计时

    Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> matrix_100 = Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic>::Random(100, 100);

    Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> v_100 = Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic>::Random(100, 1);
    time_stt = clock();
    Eigen::Matrix<float, 100, 1> x_100;
    x_100 = matrix_100.colPivHouseholderQr().solve(v_100);
    cout << "time use in Qr decomposition is " << 1000 * (clock() - time_stt) / (double)CLOCKS_PER_SEC << "ms" << endl;

    time_stt = clock();
    x_100 = matrix_100.llt().solve(v_100);
    cout << "time use in LLT decomposition is " << 1000 * (clock() - time_stt) / (double)CLOCKS_PER_SEC << "ms" << endl;

    // 2. 几何运算练习
    Eigen::Isometry3d Tc1w = Eigen::Isometry3d::Identity();
    Tc1w.pretranslate(Eigen::Vector3d(0.7, 1.1, 0.2));
    Eigen::Quaterniond q1(0.55, 0.3, 0.2, 0.2);
    q1.normalize();
    Tc1w.rotate(q1);

    Eigen::Isometry3d Tc2w = Eigen::Isometry3d::Identity();
    Eigen::Quaterniond q2(-0.1, 0.3, -0.7, 0.2);
    q2.normalize();
    Tc2w.rotate(q2);
    Tc2w.pretranslate(Eigen::Vector3d(-0.1, 0.4, 0.8));

    Eigen::Vector3d p1(0.5, -0.1, 0.2);
    Eigen::Vector3d p2;
    p2 = Tc2w * Tc1w.inverse() * p1;
    std::cout << "第二题： " << std::endl;
    std::cout << p2.transpose() << std::endl;
    // std::cout << q. << std::endl;
    return 0;
}
