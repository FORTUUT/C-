#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENG 1
char file_to_encrypto[100];			   //需要加密的文件路径及名称
char file_to_decrypto[100];			   //需要解密的文件路径及名称
char encrypted_file[50] = "encrypted"; //加密后的部分文件名
char decrypted_file[50] = "decrypted"; //解密后的部分文件名
char password[10];					   //用户输入的密码
char temp;							   //非加密部分的临时数据
unsigned int length;				   //储存原文件长度
void encrypto()
{
	system("dir");
	printf("请输入您需要加密文件的完整路径：\n");
	scanf("%100s", file_to_encrypto);						//输入需加密文件的完整路径及名称
	FILE *fp1 = fopen(file_to_encrypto, "rb"), *fp2 = NULL; //以rb方式打开需加密的文件
	if (fp1 == NULL)
	{
		printf("打开文件失败！请检查您的文件路径是否正确\n");
	}
	else
	{
		fseek(fp1, 0, 2);											  //使光标移动到文件末尾
		length = ftell(fp1);										  //返回文件的大小
		unsigned char *data = (unsigned char *)malloc(length / LENG); //我们这里加密原文件数据的十分之一
		int i, j;
		for (i = strlen(file_to_encrypto) - 1; i > 0; i--) //这里进行一个文件格式（后缀名）的截取
		{
			if (file_to_encrypto[i] == '.') //从文件名末尾往前查找到第一个'.'号，将其后的文件后缀名添加到加密文件民的末尾
			{								//若需加密文件本身没有文件后缀名，则加密后文件名也没有后缀名，即文件名为 encrypted
				int p = 0;
				for (j = i; j < strlen(file_to_encrypto); j++, p++) //文件后缀名的截取
				{
					encrypted_file[9 + p] = file_to_encrypto[j];
				}
				break;
			}
		}
		rewind(fp1);						//放回文件光标到文件头
		for (i = 0; i < length / LENG; i++) //读取原文件十分之一的数据到data
		{
			fread(&data[i], sizeof(unsigned char), 1, fp1);
		}
		printf("请输入您的加密口令(不超过10位)：\n");
		scanf("%10s", password);
		for (i = 0; i < (length / LENG) / strlen(password) + 1; i++) //将加密口令的每一位与需加密数据的每一位循环异或，保证加密的安全性
		{
			for (j = 0; j < strlen(password) && i * strlen(password) + j < (length / LENG); j++)
			{
				data[i * strlen(password) + j] ^= password[j];
			}
		}

		fp2 = fopen(encrypted_file, "wb"); //以wb方式打开二进制文件，注意不可以用w方式！
		if (fp2 == NULL)
		{
			printf("创建加密文件失败！\n");
		}
		else
		{
			for (i = 0; i < length / LENG; i++) //首先将加密后的数据写入文件
			{
				fwrite(&data[i], sizeof(unsigned char), 1, fp2);
			}
			rewind(fp1);
			if (LENG != 1)
			{
				fseek(fp1, length / LENG, 0); //使文件光标移动到文件大小的十分之一处
				while (i < length)			  //将未加密的文件数据写入加密文件，i从length/10开始，所以不需要重置i的值
				{
					fread(&temp, sizeof(unsigned char), 1, fp1); //循环写入数据
					fwrite(&temp, sizeof(unsigned char), 1, fp2);
					i++;
				}
			}
			printf("加密成功！加密文件(encrypted)已保存到您当前目录下\n");
			printf("请牢记您的加密口令！\n");
			free(data);
			fclose(fp1);
			fclose(fp2);
			getchar();
			getchar();
		}
	}
}
void decrypto()
{
	system("dir");
	printf("请输入您需要解密文件的完整路径：\n");
	scanf("%100s", file_to_decrypto); //输入需要解密的文件路径及名称
	FILE *fp1 = fopen(file_to_decrypto, "rb"), *fp2 = NULL;
	if (fp1 == NULL)
	{
		printf("打开文件失败！请检查您的文件路径是否正确\n");
	}
	else
	{
		fseek(fp1, 0, 2);
		length = ftell(fp1);										  //取得文件长度储存在length中
		unsigned char *data = (unsigned char *)malloc(length / LENG); //开辟动态内存
		int i, j;
		for (i = strlen(file_to_decrypto) - 1; i > 0; i--) //截取文件的后缀名
		{
			if (file_to_decrypto[i] == '.')
			{
				int p = 0;
				for (j = i; j < strlen(file_to_decrypto); j++, p++)
				{
					decrypted_file[9 + p] = file_to_decrypto[j];
				}
				break;
			}
		}
		rewind(fp1); //读取需解密的文件数据，即原文件数据长度的十分之一
		for (i = 0; i < length / LENG; i++)
		{
			fread(&data[i], sizeof(unsigned char), 1, fp1);
		}
		printf("请输入您的加密口令(不超过10位)：\n");
		scanf("%10s", password);
		for (i = 0; i < (length / LENG) / strlen(password) + 1; i++) //将需解密的数据与用户口令循环异或
		{
			for (j = 0; j < strlen(password) && i * strlen(password) + j < (length / LENG); j++)
			{
				data[i * strlen(password) + j] ^= password[j];
			}
		}
		fp2 = fopen(decrypted_file, "wb"); //创建解密文件
		if (fp2 == NULL)
		{
			printf("创建解密文件失败！\n");
		}
		else
		{
			for (i = 0; i < length / LENG; i++) //首先写入解密后的数据
			{
				fwrite(&data[i], sizeof(unsigned char), 1, fp2);
			}
			rewind(fp1);
			if (LENG != 1)
			{
				fseek(fp1, length / LENG, 0); //使光标移动到文件数据的十分之一处
				while (i < length)			  //将未解密的数据写入
				{
					fread(&temp, sizeof(unsigned char), 1, fp1);
					fwrite(&temp, sizeof(unsigned char), 1, fp2);
					i++;
				}
			}
			printf("解密成功！解密文件(decrypted)已保存到您当前目录下\n");
			free(data);
			fclose(fp1);
			fclose(fp2);
			getchar();
			getchar();
		}
	}
}
int main()
{
	int choice = 0;
	while (1)
	{
		system("color 0a");
		system("cls");
		printf("欢迎使用文件加密系统！\n");
		printf("请输入您的选择\n");
		printf("1.加密文件   2.解密文件   3.退出系统\n");
		scanf("%d", &choice);
		while (choice != 1 && choice != 2 && choice != 3)
		{
			printf("输入选择有误！请重新输入：");
			scanf("%d", &choice);
		}
		switch (choice)
		{
		case 1:
			encrypto();
			break;
		case 2:
			decrypto();
			break;
		case 3:
			printf("非常感谢您的使用！期待与您下次相见\n");
			system("taskkill -f -im 文件加解密系统.exe");
			break;
		}
	}
	return 0;
}
