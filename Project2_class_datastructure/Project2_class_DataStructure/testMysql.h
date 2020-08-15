#pragma once
#include<iostream>
#include"mysql.h" //数据库
//#include <mysql.h> 如果配置ok就可以直接包含这个文件
void testMySql()
{
	MYSQL mysql;    //一个数据库结构体
	MYSQL_RES* res; //一个结果集结构体
	MYSQL_ROW row;  //char** 二维数组，存放一条条记录
	//初始化数据库
	mysql_init(&mysql);
	//设置编码方式
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	//连接数据库
	//判断如果连接失败就输出连接失败。
	//注意你连接的账户名密码
	if (mysql_real_connect(&mysql, "localhost", "root", "wd3606", "course", 3306, NULL, 0) == NULL)
		std::cout << "连接失败！" << std::endl;

	//查询数据
	mysql_query(&mysql, "select * from customers");
	//获取结果集
	res = mysql_store_result(&mysql);

	//显示数据
	std::cout << "cust_id	cust_name	cust_city" << std::endl;
	//给ROW赋值，判断ROW是否为空，不为空就打印数据。
	while (row = mysql_fetch_row(res))
	{
		std::cout << row[0] << "\t" << row[1] << "\t" << row[2] << std::endl;
	}
	//释放结果集
	mysql_free_result(res);
	//关闭数据库
	mysql_close(&mysql);
}