#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


void initcontact(struct contact* ps)
{
	memset(ps->data,0,sizeof(ps->data));
	ps->size = 0;
}

void addcontact(struct contact* ps)
{
	if(ps->size == max)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s",ps->data[ps->size].name);
		printf("请输入年龄:>");
		scanf("%s",&(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf("%s",ps->data[ps->size].sex);
		printf("请输入电话:>");
		scanf("%s",ps->data[ps->size].tele);
		printf("请输入地址:>");
		scanf("%s",ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功\n");
	}
}

void showme(const struct contact* ps)
{
	if(ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");
		for(i = 0; i < ps->size;i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",ps->data[i].name,ps->data[i].age,ps->data[i].sex,ps->data[i].tele,ps->data[i].addr);
		}
	}
}

//内部子功能
static int findname(struct contact* ps,char name[max_name])
{
	int i = 0;
	for(i = 0;i<ps->size;i++)
	{
		if(0 == (strcmp(ps->data[i].name,name)));
		{
			return i;
		}
	}
	return -1;
}

void delcontact(struct contact* ps)
{
	char name[max_name];
	printf("请输入删除人的名字\n");
	scanf("%s",name);
	//1.查找要删除的人位置
	//找到了返回下标，找不到返回-1
	int pos = findname(ps,name);
	if(pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//删除数据
		int j = 0;
		for(j = pos;j<ps->size-1;j++)
		{
			ps->data[j] = ps->data[j+1];
		}
		ps->size--;
		printf("删除成功\n");
	}
	//2.删除
}

void searchcontact(struct contact* ps)
{
	char name[max_name];
	printf("请输入查找人名字\n");
	scanf("%s",name);
	int pos = findname(ps,name);
	if(pos = -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",ps->data[pos].name,ps->data[pos].age,ps->data[pos].sex,ps->data[pos].tele,ps->data[pos].addr);
	}
}

void modifycontact(struct contact* ps)
{
	char name[max_name];
	printf("请输入名字\n");
	scanf("%s",name);
	int pos = findname(ps,name);
	if(pos == -1)
	{
		printf("要修改人的信息不存在\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s",ps->data[pos].name);
		printf("请输入年龄:>");
		scanf("%s",&(ps->data[pos].age));
		printf("请输入性别:>");
		scanf("%s",ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s",ps->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s",ps->data[pos].addr);
		printf("修改成功\n");
	}
}

void sortcontact(struct contact *ps)
{
    if (ps->size <= 0)
	{
		printf("通讯录中没有联系人，请添加!\n");
	}
	int i = 0;
	int j = 0;
	for (i = 0; i< ps->size - 1; i++)
	{
		for (j = 0; j< ps->size - i - 1; j++)
		{
			if (strcmp( ps->data[j].name, ( ps->data[j + 1]).name) > 0)
			{
                people tmp;
				tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
			}
		}
		printf("排序成功！\n");
	}
}
