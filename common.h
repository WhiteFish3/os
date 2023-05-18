#ifndef __common_h__//如果未定义了common_h标识符,就要编译这个头文件
#define __common_h__
#include<sys/time.h>//导入系统时间和日期的库
#include<sys/stat.h>//导入文件状态的库
#include<assert.h>//导入断言库（用于调试）
double GetTime()//定义一个获取当前时间的函数
{
	struct timeval t;//定义一个结构体变量,表示时间
	/*
	 *struct timeval
	 *{
	 *	time_t tv_sec;//秒数（从1970年1月1日开始）
	 *	suseconds_t tv_usec;  // 微秒数
	 *};
	 */
	int rc = gettimeofday(&t, NULL);//获取开始时间
	assert(rc == 0);//如果rc变量的值为0则报错,也就是说当前时间获取失败
	return (double)t.tv_sec+(double)t.tv_usec/1e6;//返回当前时间（以秒为单位）
}
//模拟一个自旋锁
void Spin(int howlong)
{
    double t=GetTime();//获取开始时间
    while ((GetTime()-t)<(double)howlong);//执行循环直到满足条件
}
#endif//结束头文件的编写
