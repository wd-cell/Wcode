#pragma once
#include<iostream>
#include"mysql.h" //���ݿ�
//#include <mysql.h> �������ok�Ϳ���ֱ�Ӱ�������ļ�
void testMySql()
{
	MYSQL mysql;    //һ�����ݿ�ṹ��
	MYSQL_RES* res; //һ��������ṹ��
	MYSQL_ROW row;  //char** ��ά���飬���һ������¼
	//��ʼ�����ݿ�
	mysql_init(&mysql);
	//���ñ��뷽ʽ
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	//�������ݿ�
	//�ж��������ʧ�ܾ��������ʧ�ܡ�
	//ע�������ӵ��˻�������
	if (mysql_real_connect(&mysql, "localhost", "root", "wd3606", "course", 3306, NULL, 0) == NULL)
		std::cout << "����ʧ�ܣ�" << std::endl;

	//��ѯ����
	mysql_query(&mysql, "select * from customers");
	//��ȡ�����
	res = mysql_store_result(&mysql);

	//��ʾ����
	std::cout << "cust_id	cust_name	cust_city" << std::endl;
	//��ROW��ֵ���ж�ROW�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݡ�
	while (row = mysql_fetch_row(res))
	{
		std::cout << row[0] << "\t" << row[1] << "\t" << row[2] << std::endl;
	}
	//�ͷŽ����
	mysql_free_result(res);
	//�ر����ݿ�
	mysql_close(&mysql);
}