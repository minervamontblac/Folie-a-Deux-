#define _CRT_SECURE_NO_WARNINGS 1
//#define max 1000
#define max_name 20
#define max_sex 5
#define max_tele 12
#define max_addr 30
#define DEFAULT_SZ 3 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
enum option
{
	exit,
	add,
	del,
	search,
	modify,
	show,
	sort
};

typedef struct people
{
	char name[max_name];
	int age;
	char sex[max_sex];
	char tele[max_tele];
	char addr[max_addr];
}people;
//通讯录类型
struct contact
{
	struct people *data;//存放数据
	int size;//记录当前元素个数
	int capacity;
};
//声明函数
//初始化通讯录函数
void initcontact(struct contact* ps);
//增加一个人员信息
void addcontact(struct contact* ps);
//展示用户信息
void showme(const struct contact* ps);
//删除指定联系人
void delcontact(struct contact* ps);
//查找指定人信息
void searchcontact(struct contact* ps);
//修改信息
void modifycontact(struct contact* ps);
//排序通讯录内容
void sortcontact(struct contact* ps);
void destroycontact(struct contact* ps);
