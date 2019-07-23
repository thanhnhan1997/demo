#include<conio.h>
#include<stdio.h>
#include<string.h>

//COURSE_WORK1
struct nhacungcap
{
	int manccc;
	char tenncc [30];
};
struct hanghoa
{
	int mahh;
	char tenhh [30];
	char dvt [30];
};
struct chungtu
{
	int mact;
	int mancc;
	int mahh;
	int soluong;	
};


void nhapMang_NCC(nhacungcap a[], int &n)
{
	
	printf("Nhap so luong: ");
	scanf("%d", &n);
    FILE *f;
    f = fopen("nhacc.txt", "w");
    if(f == NULL)
    {
    	printf("That Bai\n");
    	
    }
    fprintf(f,"%d\n", n);
    for(int i = 0; i < n;i++)
    {
    	
    	printf("Nhap Ma: ");
    	scanf("%d", &a[i].manccc);
    	fflush stdin;
    	printf("Nhap ten NCC: ");
    	gets(a[i].tenncc);
    	fprintf(f,"%d\t",a[i].manccc);
    	fprintf(f,"%s\n", a[i].tenncc);
    }
    
    fclose(f);

}

void nhapMang_HH(hanghoa a[], int &n)
{
	printf("Nhap so luong: ");
	scanf("%d", &n);
    FILE *f;
    f = fopen("hanghoa.txt", "w");
    if(f == NULL)
    {
    	printf("That Bai\n");
    	
    }
    fprintf(f,"%d\n", n);
    for(int i = 0; i < n;i++)
    {
    	printf("Nhap Ma: ");
    	scanf("%d", &a[i].mahh);
   		fflush stdin;
    	printf("Nhap ten HH: ");
    	gets(a[i].tenhh);
    	printf("Nhap DV: ");
    	gets(a[i].dvt);
    	fprintf(f,"%d\t",a[i].mahh);
    	fprintf(f,"%s\t", a[i].tenhh);
    	fprintf(f,"%s\n", a[i].dvt);
    }
	
	fclose(f);
	
}

void nhapMang_Chtu(chungtu a[], int &n)
{
	printf("Nhap so luong: ");
	scanf("%d", &n);
    FILE *f;
    f = fopen("chungtu.txt", "w");
    if(f == NULL)
    {
    	printf("That Bai\n");
    	
    }
    fprintf(f,"%d\n", n);
    for(int i = 0; i < n;i++)
    {
    	printf("Nhap Ma Ct: ");
    	scanf("%d", &a[i].mact);
    	printf("Nhap ma NCC: ");
   		scanf("%d", &a[i].mancc);
    	printf("Nhap ma HH: ");
    	scanf("%d", &a[i].mahh);
   		printf("Nhap So Luong: ");
    	scanf("%d", &a[i].soluong);
    	fprintf(f,"%d\t",a[i].mact);
    	fprintf(f,"%d\t", a[i].mancc);
    	fprintf(f,"%d\t", a[i].mahh);
    	fprintf(f,"%d\n", a[i].soluong);
    }
	
	fclose(f);
}

void docFile_NCC(nhacungcap a[], int &n)
{
	FILE *f;
	f = fopen("nhacc.txt", "r");
	if(f == NULL)
	{
		printf("That Bai\n");
	}
	fscanf(f,"%d", &n);
	for(int i = 0;i<n;i++)
	{
		fscanf(f,"%d", &a[i].manccc);
		fscanf(f,"%s", &a[i].tenncc);
	}
}

void docFile_HH(hanghoa a[], int &n)
{
	FILE *f;
	f = fopen("hanghoa.txt", "r");
	if(f == NULL)
	{
		printf("That Bai\n");
	}
	fscanf(f,"%d", &n);
	for(int i = 0;i<n;i++)
	{
		fscanf(f,"%d", &a[i].mahh);
		fscanf(f,"%s", &a[i].tenhh);
		fscanf(f,"%s", &a[i].dvt);
	}
}

void docFile_CHTu(chungtu a[], int &n)
{
	FILE *f;
	f = fopen("chungtu.txt", "r");
	if(f == NULL)
	{
		printf("That Bai\n");
	}
	fscanf(f,"%d", &n);
	for(int i = 0;i<n;i++)
	{
		fscanf(f,"%d", &a[i].mact);
		fscanf(f,"%d", &a[i].mancc);
		fscanf(f,"%d", &a[i].mahh);
		fscanf(f,"%d", &a[i].soluong);
	}
}

void find_NCC(nhacungcap a[], int n, int index)
{
	FILE *f;
	f = fopen("output1.txt", "w");
	if(f == NULL)
	{
		printf("That Bai\n");
	}
	int count = 0;
	fprintf(f,"Thong Tin Nha Cung Cap co ma la %d:\n", index);
	for(int i = 0;i<n;i++)
	{
		if(a[i].manccc == index)
		{
	        fprintf(f,"====================\n");
			fprintf(f,"Ten Nha Cung Cap: %s\n", a[i].tenncc);
		}
		else
		{
		    count++;	
		}
	}
	if(count == n)
	{
		fprintf(f,"Khong Co Du Lieu\n");
	}
	
	fclose(f);
}

void find_HH(hanghoa a[], int n, int index)
{
	FILE *f;
	f = fopen("output2.txt", "w");
	if(f == NULL)
	{
		printf("That Bai\n");
	}
	int count = 0;
	fprintf(f,"Thong Tin Hang Hoa co ma la %d:\n", index);
	for(int i = 0;i<n;i++)
	{
		if(a[i].mahh == index)
		{
		    fprintf(f,"====================\n");	
			fprintf(f,"Ten Hang Hoa: %s\n", a[i].tenhh);
			fprintf(f,"Don Vi Tinh: %s\n", a[i].dvt);
		}
		else{
			count++;
		}
	}
	
	if(count == n)
	{
		fprintf(f,"Khong co Du Lieu\n");
	}
	fclose(f);
}

void find_CTu(chungtu a[], int n, int index)
{
	FILE *f;
	f = fopen("output3.txt", "w");
	if(f == NULL)
	{
		printf("That Bai\n");
	}
	int count = 0;
	fprintf(f,"Thong Tin Chung Tu cua Nha Cung Cap co ma la %d:\n", index);
	for(int i = 0;i<n;i++)
	{
		if(a[i].mancc == index)
		{
			fprintf(f,"====================\n");
			fprintf(f,"Ma Chung Tu: %d\n", a[i].mact);
			fprintf(f,"Ma Hang Hoa: %d\n", a[i].mahh);
			fprintf(f,"So Luong: %d\n", a[i].soluong);
		}
		else{
			count++;
		}
	}
    if(count == n)
    {
    	fprintf(f,"Khong Co Du Lieu\n");
    }
	fclose(f);
}

void lietKe_ChungTu(chungtu a[], int n)
{
	FILE *f;
	f = fopen("output4.txt", "w");
	if(f == NULL)
	{
		printf("That Bai\n");
	}
	int count = 0;
	fprintf(f,"Thong Tin Chung Tu nhap hang co so luong > 50:\n");
	for(int i = 0;i<n;i++)
	{
		if(a[i].soluong > 50)
		{
			fprintf(f,"====================\n");
			fprintf(f,"Ma Chung Tu: %d\n", a[i].mact);
			fprintf(f,"Ma Nha Cung Cap: %d\n", a[i].mancc);
			fprintf(f,"Ma Hang Hoa: %d\n", a[i].mahh);
			fprintf(f,"So Luong: %d\n",a[i].soluong);
		}
		else{
			count++;
		}
	}
	if(count == n)
	{
		fprintf(f,"Khong Co Du Lieu\n");
	}
	fclose(f);
}

void lietKe_ChungTuTrongDoan(chungtu a[], int n, int x, int y)
{
    FILE *f;
	f = fopen("output5.txt", "w");
	if(f == NULL)
	{
		printf("That Bai\n");
	}
	int count = 0;
	fprintf(f,"Thong Tin Chung Tu nhap hang co so luong nhap hang tu %d den %d don vi:\n",x,y);
	for(int i = 0;i<n;i++)
	{
		if(a[i].soluong >= x && a[i].soluong <= y)
		{
			fprintf(f,"====================\n");
			fprintf(f,"Ma Chung Tu: %d\n", a[i].mact);
			fprintf(f,"Ma Nha Cung Cap: %d\n", a[i].mancc);
			fprintf(f,"Ma Hang Hoa: %d\n", a[i].mahh);
			fprintf(f,"So Luong: %d\n", a[i].soluong);
		}
		else
		{
			count++;
		}
	}
	if(count == n)
	{
		fprintf(f,"Khong Co Du Lieu\n");
	}
	fclose(f);
}



void docFile_input(int mang[], int &n, const char *path)
{
	 FILE *f;
	
	f = fopen(path, "r");
  
	if(f == NULL)
	{
		printf("That Bai\n");
		return;
	}
    fscanf(f,"%d", &n);
  	for(int i = 0;i<n;i++)
	{
		fscanf(f,"%d", &mang[i]);
	} 
}



void docFile_input_1(int mang1[], int &n, const char *path)
{
	 FILE *f;
	
	f = fopen(path, "r");
    
	if(f == NULL)
	{
		printf("That Bai\n");
		return;
	}

  	for(int i = 0;i<n;i++)
	{
		fscanf(f,"%d", &mang1[i]);
	} 
}

void lietke_NhaCC(nhacungcap a[], int n, int tmp[], int n1)
{
	FILE *f;
	
	f = fopen("output6.txt", "w");
	
	if(f == NULL)
	{
		printf("That Bai\n");
		return;
	}
	fprintf(f,"Danh Sach Nha Cung Cap co ma so trong File: \n");
	
	for(int i = 0;i<n1;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(a[j].manccc == tmp[i])
			{
				fprintf(f,"=====================\n");
				fprintf(f,"Ma Nha Cung Cap: %d\n", a[j].manccc);
				fprintf(f,"Ten Nha Cung Cap: %s\n", a[j].tenncc);
			}
		}
		
	}
	
	fclose(f);	
}

void lietke_HH(hanghoa a[], int n, int tmp[], int n1)
{
	FILE *f;
	
	f = fopen("output7.txt", "w");
	
	if(f == NULL)
	{
		printf("That Bai\n");
		return;
	}
	fprintf(f,"Danh Sach Hang Hoa co ma so trong File: \n");
	
	for(int i = 0;i<n1;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(a[j].mahh == tmp[i])
			{
				fprintf(f,"=====================\n");
				fprintf(f,"Ma So Hang Hoa: %d\n", a[j].mahh);
				fprintf(f,"Ten Hang Hoa: %s\n", a[j].tenhh);
				fprintf(f,"Don Vi Tinh: %s\n", a[j].dvt);
			}
		}
		
	}
	
	fclose(f);	
}

void lietKe_ChungTuTrongFile(chungtu a[], int n, int tmp[], int n1)
{
    FILE *f;
	
	f = fopen("output8.txt", "w");
	
	if(f == NULL)
	{
		printf("That Bai\n");
		return;
	}
	fprintf(f,"Danh Sach Chung Tu co ma so trong File: \n");
	
	for(int i = 0;i<n1;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(a[j].mancc == tmp[i])
			{
				fprintf(f,"=====================\n");
				fprintf(f,"Ma So Chung Tu: %d\n", a[j].mact);
				fprintf(f,"Ma So Nha Cung Cap: %d\n", a[j].mancc);
				fprintf(f,"Ma So Hang Hoa: %d\n", a[j].mahh);
				fprintf(f,"So Luong: %d\n", a[j].soluong);
			}
		}
		
	}
	
	fclose(f);
}

void lietke_HH_file(chungtu a[], int n, int tmp[], int n1)
{
	 FILE *f;
	
	f = fopen("output9.txt", "w");
	
	if(f == NULL)
	{
		printf("That Bai\n");
		return;
	}
	fprintf(f,"Danh Sach Chung Tu co ma so trong File voi so luong nhap lon hon so Luong: \n");
	
	 for(int i = 0;i<n1;i+=2)
	 {
 			for(int j = 0;j<n;j++)
			{
				if(a[j].mancc == tmp[i+1] && a[j].soluong > tmp[i])
				{
					fprintf(f,"=====================\n");
					fprintf(f,"Ma So Chung Tu: %d\n", a[j].mact);
					fprintf(f,"Ma So Nha Cung Cap: %d\n", a[j].mancc);
					fprintf(f,"Ma So Hang Hoa: %d\n", a[j].mahh);
					fprintf(f,"So Luong: %d\n", a[j].soluong);
				}
			
		}
 	}
	
	
	fclose(f);
}

void sapXepMang_hh(hanghoa a[], int n)
{
     for(int i = 0;i<n-1;i++)
	 {
		 for(int j = i+1;j<n;j++)
		 {
			 if(strcmp(a[i].tenhh, a[j].tenhh) > 0)
			 {
				 hanghoa tmp = a[i];
				 a[i] = a[j];
				 a[j] = tmp;
			 }
		 }
	 }
}

void sapXepMang_hh_giamdan(hanghoa a[], int n)
{
     for(int i = 0;i<n-1;i++)
	 {
		 for(int j = i+1;j<n;j++)
		 {
			 if(strcmp(a[i].tenhh, a[j].tenhh) < 0)
			 {
				 hanghoa tmp = a[j];
				 a[j] = a[i];
				 a[i] = tmp;
			 }
		 }
	 }
}


void ghiFile_Hh(hanghoa a[], int n, const char *path)
{
	FILE *f;
	
	f = fopen(path, "w");
    
	if(f == NULL)
	{
		printf("That Bai\n");
		return;
	}

	fprintf(f,"Du Lieu Sau Khi Sap Xep (Tang Dan): \n");
  	for(int i = 0;i<n;i++)
	{
		fprintf(f,"===================\n");
		fprintf(f,"Ma So Hang Hoa: %d\n", a[i].mahh);
		fprintf(f,"Ten Hang Hoa: %s\n", a[i].tenhh);
		fprintf(f,"Don Vi Tinh: %s\n",a[i].dvt);
	} 
	
	fclose(f);
}

void ghiFile_Hh_1(hanghoa a[], int n, const char *path)
{
	FILE *f;
	
	f = fopen(path, "a");
    
	if(f == NULL)
	{
		printf("That Bai\n");
		return;
	}

	fprintf(f,"\nDu Lieu Sau Khi Sap Xep (Giam Dan): \n");
  	for(int i = 0;i<n;i++)
	{
		fprintf(f,"===================\n");
		fprintf(f,"Ma So Hang Hoa: %d\n", a[i].mahh);
		fprintf(f,"Ten Hang Hoa: %s\n", a[i].tenhh);
		fprintf(f,"Don Vi Tinh: %s\n",a[i].dvt);
	} 
	
	fclose(f);
}





int timMax_ct_SL(chungtu a[], int n)
{
	int max = a[0].soluong;
	for(int i = 1;i<n;i++)
	{
		if(a[i].soluong > max)
		{
			max = a[i].soluong;
		}
	}
	
	return max;
}

void lietKe_ChungTu_SlMax(chungtu a[], int n, const char *path)
{
	FILE *f;
	
	f = fopen(path, "w");
    
	if(f == NULL)
	{
		printf("That Bai\n");
		return;
	}

	fprintf(f,"Danh Sach Cac Chung Tu co So Luong Nhap Kho Lon Nhat: \n");
  	for(int i = 0;i<n;i++)
	{
		if(a[i].soluong == timMax_ct_SL(a, n))
		{
			fprintf(f,"===================\n");
		    fprintf(f,"Ma So Chung Tu: %d\n", a[i].mact);
		    fprintf(f,"Ma So Nha Cung Cap: %d\n", a[i].mancc);
		    fprintf(f,"Ma So Hang Hoa: %d\n",a[i].mahh);
		}
		
	} 
	
	fclose(f);
}

void sapXepMang_ct(chungtu a[], int n)
{
	for(int i = 0;i<n-1;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			if(a[i].soluong > a[j].soluong)
			{
				chungtu tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

void sapXepMang_ct_giamdan(chungtu a[], int n)
{
	for(int i = 0;i<n-1;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			if(a[i].soluong < a[j].soluong)
			{
				chungtu tmp = a[j];
				a[j] = a[i];
				a[i] = tmp;
			}
		}
	}
}

void ghiFile_Ct(chungtu a[], int n, const char *path)
{
	FILE *f;
	
	f = fopen(path, "w");
    
	if(f == NULL)
	{
		printf("That Bai\n");
		return;
	}

	fprintf(f,"Du Lieu Sau Khi Sap Xep (Tang Dan): \n");
  	for(int i = 0;i<n;i++)
	{
		fprintf(f,"===================\n");
		fprintf(f,"Ma So Chung Tu: %d\n", a[i].mact);
		fprintf(f,"Ma So Nha Cung Cap: %d\n", a[i].mancc);
		fprintf(f,"Ma So Hang Hoa: %d\n",a[i].mahh);
		fprintf(f,"So Luong: %d\n", a[i].soluong);
	} 
	
	fclose(f);
}


void ghiFile_Ct_1(chungtu a[], int n, const char *path)
{
	FILE *f;
	
	f = fopen(path, "a");
    
	if(f == NULL)
	{
		printf("That Bai\n");
		return;
	}

	fprintf(f,"\nDu Lieu Sau Khi Sap Xep (Giam Dan): \n");
  	for(int i = 0;i<n;i++)
	{
		fprintf(f,"===================\n");
		fprintf(f,"Ma So Chung Tu: %d\n", a[i].mact);
		fprintf(f,"Ma So Nha Cung Cap: %d\n", a[i].mancc);
		fprintf(f,"Ma So Hang Hoa: %d\n",a[i].mahh);
		fprintf(f,"So Luong: %d\n", a[i].soluong);
	} 
	
	fclose(f);
}


int TinhTongSlCuaX(chungtu a[], int n, int x)
{
	int tongSL = 0;
	for(int i = 0;i<n;i++)
	{
		if(a[i].mancc == x)
		{
			tongSL += a[i].soluong;
		}
	}
	
	return tongSL;
}

int ktXTonTai(chungtu a[], int n, int x, int M)
{
	int count = 1;
	int i = 0;
	if(M == 0)
	{
	    if(a[0].mancc == x)
		{
			count++;
		}
	}
	else{
		while(i<=M)
		{
			if(a[i].mancc == x)
			{
				count++;
			}
			i++;
		}
	}
	
	if(count > 1)
	{
	    return 1;	
	}
	return 0;
}

void lietKeTanSuat(chungtu a[], int n, const char *path)
{
	FILE *f;
	
	f = fopen(path, "w");
    
	if(f == NULL)
	{
		printf("That Bai\n");
		return;
	}

	fprintf(f,"Tong So Luong Nhap Hang Cua Moi Nha Cung Cap: \n");
  	
	int count = 0;
    for(int i = 0;i<n;i++)
	{
		if(ktXTonTai(a, n, a[i].mancc, i-1) == 0)
		{
			count = TinhTongSlCuaX(a, n, a[i].mancc);
			fprintf(f,"===================\n");
			fprintf(f,"Ma Nha Cung Cap: %d\n", a[i].mancc);
			fprintf(f,"Tong So Luong: %d (Don Vi)\n", count);
		}
	}	

    fclose(f);	
}


int main()
{
	nhacungcap ncc[10];
	int n1;
	hanghoa hh[10];
	int n2;
	chungtu ct[10];
	int n3;
	
	//nhapMang_NCC(ncc, n1);
	//nhapMang_HH(hh, n2);
	//nhapMang_Chtu(ct, n3);
 

    docFile_NCC(ncc, n1);
    docFile_HH(hh, n2);
    docFile_CHTu(ct, n3);
    
    //chuc nang c1: 
   find_NCC(ncc, n1, 5);
   
   //chuc nang c2:
   find_HH(hh, n2, 5);
   
   //chuc nang c3:
   find_CTu(ct, n3, 6);
   
   //chuc nang c4:
   lietKe_ChungTu(ct, n3);
   
   //chuc nang c5:
   lietKe_ChungTuTrongDoan(ct, n3, 50, 100);
   
   //chuc nang c6
   int mang[10];
   int n4;

   const char *input6_path = "input6.txt";
   docFile_input(mang, n4, input6_path);
   lietke_NhaCC(ncc, n1, mang, n4);
   
   //chuc nang c7
   const char *input7_path = "input7.txt";
   docFile_input(mang, n4, input7_path);
   lietke_HH(hh, n2, mang, n4);
   
   //chuc nang c8
   const char *input8_path = "input8.txt";
   docFile_input(mang, n4, input8_path);
   lietKe_ChungTuTrongFile(ct, n3, mang, n4);
   
   //chuc nang c9
   int mang1[2];
   int n5 = 2;
   const char *input9_path = "input9.txt";
   docFile_input_1(mang1, n5, input9_path);
   lietke_HH_file(ct, n3, mang1, n5);
   
   //chuc nang c10
   const char *output10_path = "output10.txt";
   sapXepMang_hh(hh, n1);
   ghiFile_Hh(hh, n1, output10_path);
   sapXepMang_hh_giamdan(hh, n1);
   ghiFile_Hh_1(hh, n1, output10_path);
   
   //chuc nang c11
   const char *output11_path = "output11.txt";
   lietKe_ChungTu_SlMax(ct, n3, output11_path);
   
   //chuc nang c12
   const char *output12_path = "output12.txt";
   sapXepMang_ct(ct, n3);
   ghiFile_Ct(ct, n3, output12_path);
   sapXepMang_ct_giamdan(ct, n3);
   ghiFile_Ct_1(ct, n3, output12_path);
   
   //chuc nang c13
   const char *output13_path = "output13.txt";
   lietKeTanSuat(ct, n3, output13_path);
   
   printf("DONE!!!\n");
   getch();   
}

