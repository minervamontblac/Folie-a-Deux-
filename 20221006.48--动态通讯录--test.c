#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("*****************************************\n");
	printf("*****1.add                 2.del*********\n");
	printf("*****3.search              4.modify******\n");
	printf("*****5.show                6.sort********\n");
	printf("*****0.exit                        ******\n");
	printf("*****************************************\n");
}

int main()
{
	int input = 0;
	struct contact con;//con就是通讯录包含1000个元素
	//初始化通讯录
	initcontact(&con);
	do
	{
		menu();
		printf("请选择:>\n");
		scanf("%d",&input);
		switch(input)
		{
			case add:
				addcontact(&con);
				break;
			case del:
				delcontact(&con);
				break;
			case search:
				searchcontact(&con);
				break;
			case modify:
				modifycontact(&con);
				break;
			case show:
				showme(&con);
				break;
			case sort:
				sortcontact(&con);
				break;
			case exit:
				destroycontact(&con);
				printf("退出\n");
				break;
			default:
				printf("选择错误\n");
				break;
		}
	}
	while(input);
	return 0;
}
