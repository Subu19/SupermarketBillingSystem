#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <string.h>
void alert();
void info();
void theme();
void registerUser();
int askPassword();
void checkSelection(int ,int);
void redirect(int);
void menu(int);
void viewLowStock();
void createBill();
void manageStock(int);
void changePass();
void addProduct();
void stockRedirect(int);
void getProductRedirect(int);
void getProduct();
void getProductMenu(int);
void searchByC();
void searchByName();
void searchAllProduct();
void editProduct();
void deleteProduct();
int scan = 0;
int theight=0;
void addrow(int id, int qt);
int getText(char[], int, int, int) ;
struct product{
	char name[20];
	char category[20];
	int quantity;
	int price;
	int id;
};
struct user {
	char username[20];
	char password[20];
};
void main()
{
int gd = DETECT, gm;
char array[100];
int passwordStatus;
FILE *fptr;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
theme();
	//set border and title
	againPassword:
	//ask password

fptr = fopen("password.bin","r");
if (fptr == NULL){
//		gotoxy(tX/2, tY/2);
		registerUser();
//		system("cls");
		goto againPassword;
	}else{
		passwordStatus = askPassword();
		if(passwordStatus == 1){
//wrong password
			alert();
			outtext("Wrong password!");
			getch();
			goto againPassword;

		}else if(passwordStatus == 0){
//correct password
			info();
			outtext("Correct password!");
			getch();
			menu(1);
		}
	}
    fclose(fptr);
getch()
;
closegraph();
}

void theme(){

int h,w;
h = getmaxy();
w = getmaxx();
setfillstyle(SOLID_FILL, WHITE);
setcolor(WHITE);
rectangle(0,0,w,h);
floodfill(10,10,WHITE);
setcolor(DARKGRAY);
setfillstyle(SOLID_FILL, LIGHTGRAY);
line(0,0,10,10);
line(10,10,10,h-10);
line(10,h-10,0,h);
floodfill(5,20,DARKGRAY);
line(0,h,10,h-10);
line(10,h-10,w-10,h-10);
line(w-10,h-10,w,h);
floodfill(20,h-5,DARKGRAY);
setcolor(LIGHTGRAY);
setfillstyle(SOLID_FILL, DARKGRAY);
line(0,0,10,10);
line(10,10,w-10,10);
line(w-10,10,w,0);
floodfill(20,5,LIGHTGRAY);
line(w,0,w-10,10);
line(w-10,10,w-10,h-10);
line(w-10,h-10,w,h);
floodfill(w-5,20,LIGHTGRAY);
setcolor(BLACK);
setfillstyle(SOLID_FILL, CYAN);
line(10,10,w-10,10);
line(w-10,10,w-10,90);
line(w-10,90,w-20,70);
line(w-20,70,20,70);
line(20,70,10,90);
line(10,90,10,10);
floodfill(20,20,BLACK);

setcolor(LIGHTGREEN);
settextstyle(0,HORIZ_DIR,2);
outtextxy(w/2-200,30,"Supermarket Billing System");
};

void alert(){
	int w;
	w = getmaxx();
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	rectangle(100,80,w-100,130);
	floodfill(110,110,RED);
	setcolor(WHITE);
	moveto(110,90);
	settextstyle(0,HORIZ_DIR,2);
}
void info(){
	int w;
	w = getmaxx();
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,GREEN);
	rectangle(100,80,w-100,130);
	floodfill(110,110,BLUE);
	setcolor(BLACK);
	moveto(110,90);
	settextstyle(0,HORIZ_DIR,2);
}
void registerUser(){
	//outtextxy(200,200,"register");
//	getch();
	FILE *fptr;
	char c,p, password[20];
	int w= getmaxx(), userPos=0,passPos=0,end1=0, end2=0;
	struct user usr[1];
	cleardevice();
	theme();
	setcolor(GREEN);
	rectangle(100, 150,w-100,300);
	outtextxy(110,160,"REGISTER");
	setcolor(BLACK);
	settextstyle(0, HORIZ_DIR, 1);
	outtextxy(110,190,"Username: ");
	outtextxy(110,210,"Password: ");
	usr[0].username[0]=0;
	do{
		outtextxy(200,190, usr[0].username);
		c= getch();
		switch(c){
			case 8:
				if(userPos){
				userPos--;
				usr[0].username[userPos]=0;
				}
				break;
			case 13:
				end1=1;
				break;
			case 27:
				usr[0].username[0] = 0;
				end1 =1;
				break;
			default:
				if(userPos < 19 && c>= ' ' && c <= '~' ){
				usr[0].username[userPos] = c;
				userPos++;
				usr[0].username[userPos] = 0;
				}

		}
	}while(!end1);

	password[0]= 0;
	usr[0].password[0]=0;
	do{
		outtextxy(200,210, password);
		p= getch();
		switch(p){
			case 8:
				if(passPos){
				passPos--;
				usr[0].password[passPos]=0;
				password[passPos]=0;
				}
				break;
			case 13:
				end2=1;
				break;
			case 27:
				usr[0].password[0] = 0;
				password[0] = 0;
				end2 =1;
				break;
			default:
				if(passPos < 19 && p>= ' ' && p <= '~' ){
				usr[0].password[passPos] = p;
				password[passPos] = '*';
				passPos++;
				usr[0].password[passPos] = 0;
				password[passPos] = 0;
				}

		}
	}while(!end2);

	fptr = fopen("password.bin","wb");
	fwrite(usr, sizeof(struct user),1, fptr);
	fclose(fptr);
	getch();
}

int askPassword(){
       //	outtextxy(200,200,"login");
       //	getch();
	FILE *fptr;
	char username[20];
	char password[20], password2[20];
	struct user usr[1];
	char c,p;

	int w= getmaxx(), userPos=0,passPos=0,end1=0, end2=0;
	cleardevice();
	theme();
	setcolor(GREEN);
	rectangle(100, 150,w-100,300);
	outtextxy(110,160,"LOGIN");
	setcolor(BLACK);
	settextstyle(0, HORIZ_DIR, 1);
	outtextxy(110,190,"Username: ");
	outtextxy(110,210,"Password: ");
	username[0]=0;
	do{
		outtextxy(200,190, username);
		c= getch();
		switch(c){
			case 8:
				if(userPos){
				userPos--;
				username[userPos]=0;
				}
				break;
			case 13:
				end1=1;
				break;
			case 27:
				username[0] = 0;
				end1 =1;
				break;
			default:
				if(userPos < 19 && c>= ' ' && c <= '~' ){
				username[userPos] = c;
				userPos++;
				username[userPos] = 0;
				}

		}
	}while(!end1);

	password2[0]=0;
	password[0]=0;
	do{
		outtextxy(200,210, password2);
		p= getch();
		switch(p){
			case 8:
				if(passPos){
				passPos--;
				password[passPos]=0;
				password2[passPos]=0;
				}
				break;
			case 13:
				end2=1;
				break;
			case 27:
				password[0] = 0;
				password2[0]=0;
				end2 =1;
				break;
			default:
				if(passPos < 19 && p>= ' ' && p <= '~' ){
				password[passPos] = p;
				password2[passPos]='*';
				passPos++;
				password[passPos] = 0;
				password2[passPos] = 0;
				}

}

	}while(!end2);

	fptr = fopen("password.bin","rb");
	fread(&usr, sizeof(struct user), 1, fptr);
	fclose(fptr);
	if((strcmp(username, usr[0].username)==0) && (strcmp(password,usr[0].password)==0)){
		return 0;
	}else{
		return 1;
	}

}

void menu(int o){
	FILE *fp;
	char c,buff[80],lowStockC[20];
	int w=getmaxx(), h=getmaxy(),end=0,i,j,x_dis,flag=0, lowStock=0;
	struct product pdt[1];
	cleardevice();

	theme();
	setcolor(BLACK);
	outtextxy(300, 90, "Menu");
	rectangle(100,130,w-100, h-50 );
	floodfill(105,135, BLACK);
	settextstyle(0, HORIZ_DIR, 1);
	outtextxy(12,h-20,"Use 1,2,3... keys to negivate options.");

	rectangle(150, 150, w-150, 180);
	checkSelection(o,1);
	floodfill(152, 152, BLACK);
	outtextxy(155,162, "1. Create Bill");

	rectangle(150, 200, w-150, 230);
	checkSelection(o,2);
	floodfill(152, 202, BLACK);
	outtextxy(155,212, "2. Manage Stock");

	rectangle(150, 250, w-150, 280);
	checkSelection(o,3);
	floodfill(152, 252, BLACK);
	outtextxy(155,262, "3. Change Password");

	rectangle(150, 320, 220, 340);
	setfillstyle(SOLID_FILL, RED);
	floodfill(152, 322, BLACK);
	setcolor(WHITE);
	outtextxy(157, 327, "Exit(x)");
	setcolor(BLACK);
	j=0;
	x_dis=0;
	if(scan == 0){
	for(i=0;i<=250;i++){
		if(x_dis == 100){
			flag = 1;
		}else if(x_dis == 0){
			flag= 0;
		}
		if(flag == 1){
		x_dis--;
		}else if(flag == 0) {
		x_dis++;
		}
		setcolor(BLACK);
		rectangle(w-150,h-40,w-30, h-20);
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		floodfill(w-148,h-35,BLACK);
		setcolor(GREEN);
		rectangle(w-150+ x_dis, h-40, w-130+x_dis,h-20);
		setfillstyle(SOLID_FILL, GREEN);
		floodfill(w-148+x_dis,h-35,GREEN);
		delay(15);
		}
	}
	if(scan == 0){
	for(i=10;i<=200;i++){
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW);
		rectangle(w,h-80, w-i,h-20);
		floodfill(w-5, h-70, YELLOW);
		delay(2);

	}
	scan=1;
		fp = fopen("product.txt", "r");
		if(fp==NULL){
		alert();
		outtext("file not found");
		}
		while(fread(&pdt, sizeof(struct product), 1, fp)){
			if(pdt[0].quantity <20){
				lowStock++;
			}
		}
		fclose(fp);
		if(lowStock !=0){
			setcolor(BLACK);
			settextstyle(0, HORIZ_DIR, 1);
			sprintf(lowStockC, "%d", lowStock);
			setcolor(RED);
			outtextxy(w-190, h-70, lowStockC);
			setcolor(BLACK);
			outtextxy(w-179, h-70, "Items are low on stock!");
			setcolor(LIGHTGRAY);
			outtextxy(w-190, h-50,"Press (e) to view." );
		}
	}else{
	     setcolor(BLACK);
	     line(w-50, h-50, w-20,h-15);
	     line(w-20, h-15, w-80, h-15);
	     line(w-80,h-15, w-50,h-50);
	     setfillstyle(SOLID_FILL,YELLOW);
	     floodfill(w-50,h-30, BLACK);
	     settextstyle(0, HORIZ_DIR, 3);
	     outtextxy(w-58,h-40, "!");
	     setcolor(BLACK);
	     settextstyle(0,HORIZ_DIR, 1);
	     outtextxy(w-58,h-70,"(e)");
	}
	do{
	       c= getch();
	       switch(c){
			case '1':
				if(o!=1){
				o=1;
				menu(o);
				end=1;
				}
				break;
			case '2':
				if(o!=2){
				o=2;
				menu(o);
				end=1;
				}
				break;

			case '3':
				if(o!=3) {
				o=3;
				menu(o);
				end=1;
				}
				break;
			case 'e':
				viewLowStock();
				break;
			case '\r':
				end=1;
				redirect(o);
				break;
			default:
				if(c=='x'){
				end=1;
				}
				break;


	       }
	}while(!end);
}
void viewLowStock(){
	char category[20],price[20],quantity[20],c,countC[20],tmpId[20];
	int w= getmaxx(), h= getmaxy(),height=180,id,end=0,count=0,i=0, perPage;
	struct product pdt[1], pdt1[100];
	FILE *fp;
	cleardevice();
	theme();
	info();
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	outtext("Low On Stock");
	setcolor(BLACK);
	rectangle(100,130,w-100, h-50 );
	floodfill(110,135, BLACK);
	settextstyle(0, HORIZ_DIR, 1);
	fp = fopen("product.txt", "r");
	if(fp == NULL){
	alert();
	outtext("Error");
	return;
	}
	while(fread(&pdt, sizeof(struct product), 1, fp)){
		if(pdt[0].quantity <= 20){
			pdt1[count] = pdt[0];
			count++;
		}


	}
	perPage = (((h-100)-180)/40);
	if(count>0){
		sprintf(countC, "%d", count);
		setcolor(WHITE);
		outtextxy(120,160,"Found ");
		setcolor(YELLOW);
		outtextxy(165,160,countC);
		setcolor(WHITE);
		outtextxy(178,160,"products low on stock!");
		nextpage:
		if(i>0 && i<count){
			setcolor(BLACK);
			rectangle(280,h-80, 360, h-60);
			setfillstyle(SOLID_FILL, GREEN);
			floodfill(282, h-76, BLACK);
			settextstyle(0, HORIZ_DIR, 1);
			outtextxy(286, h-74, "Prev(a)");
		}
		while(height <= h-100){
			if(i<count){
				settextstyle(0, HORIZ_DIR, 1);
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, WHITE);
				rectangle(150, height, w-150, height+30);
				floodfill(152, height+2, BLACK);
				sprintf(tmpId, "ID: %d", pdt1[i].id);
				outtextxy(155, height+12, tmpId);
				setcolor(MAGENTA);
				outtextxy(215,height+12, pdt1[i].name);
				sprintf(price, "Rs: %d",pdt1[i].price);
				setcolor(GREEN);
				outtextxy(310,height+12,price);
				setcolor(BLACK);
				sprintf(quantity, "QT: %d", pdt1[i].quantity);
				outtextxy(400, height+12, quantity);
				i++;

			}
			height=height+40;

		}
		height=180;
		setcolor(BLACK);
		rectangle(120,h-80, 200, h-60);
		setfillstyle(SOLID_FILL, RED);
		floodfill(122, h-76, BLACK);
		setcolor(WHITE);
		outtextxy(126, h-74, "<=Exit(x)");

		if(i<count){
			setcolor(BLACK);
			rectangle(w-195, h-80, w-120, h-60);
			setfillstyle(SOLID_FILL, GREEN);
			floodfill(w-192, h-78, BLACK);
			outtextxy(w-188, h-74, "Next(d)");
		}
		end=0;
		while(!end){
			c=getch();
			switch(c){
				case 'a':
					if(i> perPage ){
					    if(i> (count -(count % perPage ))){
						 i =  i-(perPage+ (count % perPage));
					    }else{
						i = i- (2 * perPage);
					    }
					    height=180;

					    cleardevice();
					    theme();
					    info();
					    outtext("Low On Stock");
					    setfillstyle(SOLID_FILL, LIGHTBLUE);
					    setcolor(BLACK);
					    rectangle(100,130,w-100, h-50 );
					    floodfill(110,135, BLACK);
					    setcolor(WHITE);
					    settextstyle(0, HORIZ_DIR, 1);
					    outtextxy(120,160,"Found ");
					    setcolor(YELLOW);
					    outtextxy(165,160,countC);
					    setcolor(WHITE);
					    outtextxy(178,160,"products low on stock!");
					    end =1;
					    goto nextpage;
					}
					break;
				case 'd':
					if(i<count){
					height=180;
					cleardevice();
					theme();
					info();
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					setcolor(BLACK);
					rectangle(100,130,w-100, h-50 );
					floodfill(110,135, BLACK);
					outtext("Low On Stock");
					settextstyle(0, HORIZ_DIR, 1);
					setcolor(WHITE);
					outtextxy(120,160,"Found ");
					setcolor(YELLOW);
					outtextxy(165,160,countC);
					setcolor(WHITE);
					outtextxy(178,160,"products low on stock!");
					setcolor(BLACK);
					end =1;
					goto nextpage;
					}
					break;
				case 'x':
					end=1;
					menu(1);
					break;
				default:
					break;

			}
		}







	}else{
		outtextxy(120,155,"0 product found :( ");
		getch();
	}
	fclose(fp) ;

}
void checkSelection(int o,int n){
	if(o == n){
		setfillstyle(SOLID_FILL, GREEN);
	}else{
		setfillstyle(SOLID_FILL, WHITE);
	}
}

void redirect(int o){
	if(o==1)
	createBill();
	else if(o==2)
	manageStock(1);
	else if(o==3)
	changePass();
	else{
	cleardevice();
	theme();
	alert();
	outtext("LOL, i am lost");
	}
}
void stockRedirect(int o){
	if(o==1)
	addProduct();
	else if(o==2)
	getProductMenu(1);
	else if(o==3)
	editProduct();
	else if(o == 4)
	deleteProduct();
	else{
	cleardevice();
	theme();
	alert();
	outtext("LOL, i am lost");
	}
}
void getProductRedirect(int o){
	if(o==1)
	getProduct();
	else if(o==2)
	searchByC();
	else if(o==3)
	searchByName();
	else if(o==4)
	searchAllProduct();
	else{
	cleardevice();
	theme();
	alert();
	outtext("LOL, i am lost");
	}
}
void createBill(){
	int h= getmaxy(), w= getmaxx(),AD=0,id, QT, found=1,discount,Ipayment,Ichange;
	float total=0, tax=0;
	char c,gtotal[20],cdiscount[20],ctax[20],ctotal[20],payment[20],change[20];
	struct product pdt;
	char tmpId[20], tmpQT[20];
	FILE *fp, *fp2;
	cleardevice();
	theme();
	setcolor(BLACK);
	settextstyle(0, HORIZ_DIR, 1);
	rectangle(w-200, 100, w-20, h-20);
	setfillstyle(SOLID_FILL, CYAN);
	floodfill(w-195, 155, BLACK);
	rectangle(20, 100, w-210,h-20);
	line(20,130,w-210, 130);
	outtextxy(25, 113, "ID");
	outtextxy(60, 113, "PRODUCT");
	outtextxy(220,113,"PRICE" );
	outtextxy(290,113, "QT");
	outtextxy(350, 113, "TOTAL");
	line(20, h-100, w-210, h-100);
	outtextxy(25, h-94, "TOTAL");
	line(20, h-80, w-210, h-80);
	outtextxy(25, h-74, "TAX");
	line(20, h-60, w-210, h-60);
	outtextxy(25, h-54, "DISCOUNT");
	line(20, h-40, w-210, h-40);
	outtextxy(25, h-34, "GRAND TOTAL");
	line(w-410, h-100, w-410, h-20);
	fp = fopen("product.txt", "r");
	fp2 = fopen("temp.txt", "w");
	while(fread(&pdt, sizeof(pdt), 1, fp)){
		fwrite(&pdt, sizeof(pdt), 1, fp2);
	}
	fclose(fp);
	fclose(fp2);
	while(!AD){
		if(theight <=240){
		found = 1;
		setcolor(BLACK);
		settextstyle(0, HORIZ_DIR, 1);
		rectangle(w-200, 100, w-20, h-20);
		setfillstyle(SOLID_FILL, WHITE);
		floodfill(w-195, 155, BLACK);
		setfillstyle(SOLID_FILL, CYAN);
		floodfill(w-195, 155, BLACK);
		outtextxy(w-150, 130,"ADD PRODUCT");
		setcolor(WHITE);
		outtextxy(w-190,150,"Enter product ID: ");
		getText(tmpId,w-40,150,20);
		sscanf(tmpId, "%d", &id);
		fp = fopen("temp.txt", "r");
		fp2 = fopen("temp2.txt", "w");
		while(fread(&pdt, sizeof(struct product), 1, fp)){
			if(pdt.id == id){
			found =0;
			setcolor(LIGHTGREEN);
			outtextxy(w-190,180, "Product Found!" );
			setcolor(WHITE);
			outtextxy(w-190, 200, "Name: ");
			outtextxy(w-140, 200, pdt.name);
			outtextxy(w-190,220,"Enter Quantity: ");
			getText(tmpQT,w-40,220,20);
			sscanf(tmpQT, "%d", &QT);
			setcolor(LIGHTGREEN);
			rectangle(w-170, 250, w-50, 270);
			setfillstyle(SOLID_FILL, GREEN);
			floodfill(w-168, 252, LIGHTGREEN);
			setcolor(WHITE);
			outtextxy(w-145, 258, "ADD? (y/n)");
			c = getch();
			if(c != 'n'){
			      setcolor(LIGHTGREEN);
			      outtextxy(w-190, 280, "Added!");
				addrow(id, QT);
				pdt.quantity = pdt.quantity - QT;
				total += QT * pdt.price;

			}else{
				setcolor(RED);
				outtextxy(w-190, 280, "Not Added!");
			}
			}
			fwrite(&pdt, sizeof(pdt), 1, fp2);

		}
		fclose(fp);
		fclose(fp2);
		fp = fopen("temp2.txt", "r");
		fp2 = fopen("temp.txt", "w");
		while(fread(&pdt, sizeof(pdt), 1, fp)){
		fwrite(&pdt, sizeof(pdt), 1, fp2);
		}
		fclose(fp);
		fclose(fp2);
		if(found == 1){
		 outtextxy(w-190, 280, "Product Not Found!");
		}
		setcolor(LIGHTGREEN);
		rectangle(w-170,300, w-50, 320);
		setfillstyle(SOLID_FILL, GREEN);
		floodfill(w-168, 302, LIGHTGREEN);
		setcolor(WHITE);
		outtextxy(w-165,308, "CONTINUE?(y/n)");
		c = getch();
		if(c != 'n'){
		      AD=0;
		}else{
			AD=1;
		}
		}//top if close
		else{
		AD=1;
		}
	}//while close
	setcolor(DARKGRAY);
	settextstyle(0, HORIZ_DIR, 1);
	rectangle(w-200, 100, w-20, h-20);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(w-195, 155, DARKGRAY);
	setfillstyle(SOLID_FILL, CYAN);
	floodfill(w-195, 155, DARKGRAY);
	setcolor(BLACK);
	outtextxy(w-150, 130,"ADD DISCOUNT");
	setcolor(WHITE);
	outtextxy(w-190, 150, "Enter discount: ");
	getText(cdiscount, w-60, 150, 20);
	setcolor(BLACK);
	sprintf(ctotal, "%.2f", total);
	outtextxy(w-400, h-94, ctotal);
	outtextxy(w-400,h-74, "13% = ");
	tax = 0.13 * total;
	sprintf(ctax, "%.2f", tax);
	outtextxy(w-350, h-74, ctax);
	total = total + tax;
	outtextxy(w-400, h-54 ,cdiscount);
	sscanf(cdiscount, "%d", &discount);
	total = total - discount;
	sprintf(gtotal, "%.2f", total);
	outtextxy(w-400, h-34, gtotal);

	setcolor(DARKGRAY);
	settextstyle(0, HORIZ_DIR, 1);
	rectangle(w-200, 100, w-20, h-20);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(w-195, 155, DARKGRAY);
	setfillstyle(SOLID_FILL, CYAN);
	floodfill(w-195, 155, DARKGRAY);
	setcolor(BLACK);
	outtextxy(w-170, 130,"Payment Method:");
	rectangle(w-190, 150, w-120, 170);
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(w-188, 152, BLACK);
	outtextxy(w-186, 157, "Cash(z)");
	rectangle(w-100, 150, w-30, 170);
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(w-78, 152, BLACK);
	outtextxy(w-90, 157, "Card(x)");
	checkagain:
	c=getch();
	if(c=='z'){
		outtextxy(w-190, 180, "Cash Payment: ");
		getText(payment, w-70, 180, 20);
		sscanf(payment, "%d", &Ipayment);
		Ichange = Ipayment - total;
		setcolor(WHITE);
		outtextxy(w-190, 200, "Change: ");
		sprintf(change, "%d", Ichange);
		outtextxy(w-70,200, change);
	}
	else if(c=='x'){
		setcolor(LIGHTGREEN);
		outtextxy(w-190, 180, "Money deducted!");

	}else{
	goto checkagain;
	}
	setcolor(BLACK);
	outtextxy(w-170, 250,"Confirm Purchase?");
	rectangle(w-190, 270, w-130, 290);
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(w-188, 272, BLACK);
	outtextxy(w-183, 277, "Yes(Y)");
	rectangle(w-80, 270, w-30, 290);
	setfillstyle(SOLID_FILL, RED);
	floodfill(w-78, 272, BLACK);
	outtextxy(w-73, 277, "No(N)");
	c=getch();
	if(c !='n'){
		fp = fopen("temp.txt", "r");
		fp2 = fopen("product.txt", "w");
		while(fread(&pdt, sizeof(pdt), 1, fp)){
			fwrite(&pdt, sizeof(pdt), 1, fp2);
		}
		fclose(fp);
		fclose(fp2);
		info();
		outtext("Purchase Successful");
		theight=0;
		getch();
		menu(1);
	}else{
		alert();
		outtext("Purchase failed!");
		theight=0;
		getch();
		menu(1);
	}
}

void addrow(int id, int qt){
	int pTotal;
	char tmpId[20],price[20],quantity[20], proTotal[20];
	struct product pdt[1];
	FILE *fp;
	sprintf(tmpId, "%d", id);
	sprintf(quantity, "%d", qt);
	fp = fopen("product.txt", "r");
	setcolor(DARKGRAY);
	while(fread(&pdt, sizeof(struct product), 1, fp)){
		if(pdt[0].id == id){
			outtextxy(25, 135+ theight, tmpId);
			outtextxy(60, 135+theight, pdt[0].name);
			sprintf(price, "%d", pdt[0].price);
			outtextxy(220,135+theight,price);
			outtextxy(290,135+theight, quantity);
			pTotal = pdt[0].price * qt;
			sprintf(proTotal, "%d", pTotal);
			outtextxy(350, 135+ theight, proTotal);
		}

	}
	theight += 20;
	fclose(fp);


}
void manageStock(int o){
	int h= getmaxy(), w= getmaxx(), end=0;
	char c;
	cleardevice();
	theme();
	info();
	outtext("Lets manage stock.");
	setcolor(BLACK);
	rectangle(100,130,w-100, h-50 );
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	floodfill(105,135, BLACK);
	settextstyle(0, HORIZ_DIR, 1);
	outtextxy(12,h-20,"Use 1,2,3...keys to negivate options.");

	rectangle(150, 150, w-150, 180);
	checkSelection(o,1);
	floodfill(152, 152, BLACK);
	outtextxy(155,162, "1. Add Product");

	rectangle(150, 200, w-150, 230);
	checkSelection(o,2);
	floodfill(152, 202, BLACK);
	outtextxy(155,212, "2. Get Product");

	rectangle(150, 250, w-150, 280);
	checkSelection(o,3);
	floodfill(152, 252, BLACK);
	outtextxy(155,262, "3. Edit Product");

	rectangle(150, 300, w-150, 330);
	checkSelection(o,4);
	floodfill(152, 302, BLACK);
	outtextxy(155,312, "4. Delete Product");

	setcolor(BLACK);
		rectangle(120,h-80, 200, h-60);
		setfillstyle(SOLID_FILL, GREEN);
		floodfill(122, h-76, BLACK);
		outtextxy(126, h-74, "<=Back(x)");
	do{
	       c= getch();
	       switch(c){
			case '1':
				if(o!=1){
				o=1;
				manageStock(o);
				end=1;
				}
				break;
			case '2':
				if(o!=2){
				o=2;
				manageStock(o);
				end=1;
				}
				break;

			case '3':
				if(o!=3) {
				o=3;
				manageStock(o);
				end=1;
				}
				break;
			case '4':
				if(o!=4) {
				o=4;
				manageStock(o);
				end=1;
				}
				break;
			case 'x':
				menu(1);
				end=1;
				break;
			case '\r':
				end=1;
				stockRedirect(o);
				break;
			default:
				if(c=='y'){
				end=1;
				}


	       }
	}while(!end);
}
void addProduct(){
	int w= getmaxx(), h= getmaxy(),qt, price,n;
	char name[20],category[20], tmpPrice[20], tmpQt[20],c,tmpId[20];
	FILE *fp, *fp1;
	struct product pdt[1];
	struct product pdt1[1];
	cleardevice();
	theme();
	info();
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	outtext("Add Product");
	setcolor(BLACK);
	rectangle(100,130,w-100, h-50 );
	floodfill(105,135, BLACK);
	setcolor(WHITE);
	settextstyle(0, HORIZ_DIR, 1);
	outtextxy(120, 140, "Product name: ");
	getText(pdt[0].name, 260, 140,20);
	outtextxy(120, 160, "Category:");
	getText(pdt[0].category, 260, 160,20);
	outtextxy(120, 180,"Price(each): ");
	getText(tmpPrice, 260, 180, 20);
	sscanf(tmpPrice, "%d", &price);
	outtextxy(120, 200, "Quantity: ");
	getText(tmpQt, 260, 200, 20);
	sscanf(tmpQt, "%d", &qt);
	pdt[0].quantity = qt;
	pdt[0].price = price;
	fp = fopen("product.txt", "a+");
	fp1= fopen("product.txt","r");
	if(fp == NULL){
		alert();
		outtext("Error while getting DB");
	}else{
		fseek(fp,0,SEEK_END);
	       n = ftell(fp)/sizeof(pdt);
	       sprintf(tmpId, "%d", n);
			outtextxy(180, 260, tmpId);
	       if(n>0){
		while(fread(&pdt1, sizeof(struct product), 1, fp1)){
			n = pdt1[0].id + 1;
			sprintf(tmpId, "%d", pdt1[0].id);
			outtextxy(180, 240, tmpId);
		}
		}else{
		n=1;
		}
		pdt[0].id =n;
		fwrite(&pdt[0], sizeof(pdt), 1, fp);
	}
	fclose(fp);
	fclose(fp1);
	alert();
	info();
	settextstyle(0, HORIZ_DIR, 1);
	setcolor(WHITE);
	outtext("Successfully added the product! Add more? (y/n)");
	c= getch();
	if(c == 'y'){
		addProduct();
	}else{
		manageStock(1);
	}
}

int getText(char *str, int x, int y,int n){
	int end=0,txtPos=0;
	char c;
	str[0]=0;
	do{
		outtextxy(x,y, str);
		c= getch();
		switch(c){
			case 8:
				if(txtPos){
				txtPos--;
				str[txtPos]=0;
				}
				break;
			case 13:
				end=1;
				break;
			case 27:
				str[0] = 0;
				end =1;
				break;
			default:
				if(txtPos < n-1 && c>= ' ' && c <= '~' ){
				str[txtPos] = c;
				txtPos++;
				str[txtPos] = 0;
				}

		}
	}while(!end);
   return 0;
}
void getProductMenu(int o){
	int h= getmaxy(), w= getmaxx(),end=0;
	char c;
	cleardevice();
	theme();
	info();
	outtext("Lets Search Product");
	setcolor(BLACK);
	rectangle(100,130,w-100, h-50 );
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	floodfill(105,135, BLACK);
	settextstyle(0, HORIZ_DIR, 1);
	outtextxy(12,h-20,"Use 1,2,3...keys to negivate options.");

	rectangle(150, 150, w-150, 180);
	checkSelection(o,1);
	floodfill(152, 152, BLACK);
	outtextxy(155,162, "1. Search By Id");

	rectangle(150, 200, w-150, 230);
	checkSelection(o,2);
	floodfill(152, 202, BLACK);
	outtextxy(155,212, "2. Search by Category");

	rectangle(150, 250, w-150, 280);
	checkSelection(o,3);
	floodfill(152, 252, BLACK);
	outtextxy(155,262, "3. Search by Name");

	rectangle(150, 300, w-150, 330);
	checkSelection(o,4);
	floodfill(152, 302, BLACK);
	outtextxy(155,312, "4. Search all Products");
	setcolor(BLACK);
		rectangle(120,h-80, 200, h-60);
		setfillstyle(SOLID_FILL, GREEN);
		floodfill(122, h-76, BLACK);
		outtextxy(126, h-74, "<=Back(x)");
	do{
	       c= getch();
	       switch(c){
			case '1':
				if(o!=1){
				o=1;
				getProductMenu(o);
				end=1;
				}
				break;
			case '2':
				if(o!=2){
				o=2;
				getProductMenu(o);
				end=1;
				}
				break;
			case '3':
				if(o!=3){
				o=3;
				getProductMenu(o);
				end=1;
				}
				break;
			case '4':
				if(o!=4){
				o=4;
				getProductMenu(o);
				end=1;
				}
				break;
			case 'x':
				menu(1);
				end=1;
				break;
			case '\r':


				end=1;
				getProductRedirect(o);
				break;
			default:
				if(c=='y'){
				end=1;
				}
				break;


	       }
	}while(!end);

}

void getProduct(){
	char tmpId[20],price[20],quantity[20],c;
	int w= getmaxx(), h= getmaxy(),i=10,id,found=1;
	struct product pdt[1];
	FILE *fp;
	cleardevice();
	theme();
	info();
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	outtext("Get Product");
	setcolor(BLACK);
	rectangle(100,130,w-100, h-50 );
	floodfill(110,135, BLACK);
	settextstyle(0, HORIZ_DIR, 1);
	setcolor(WHITE);
	outtextxy(120,145,"Enter product ID: ");
	getText(tmpId,260,145,20);
	sscanf(tmpId, "%d", &id);
	fp = fopen("product.txt", "r");
	while(fread(&pdt, sizeof(struct product), 1, fp)){
		if(pdt[0].id == id){
		settextstyle(0, HORIZ_DIR, 2);
		setcolor(YELLOW);
		outtextxy(120,180, pdt[0].name);
		settextstyle(0, HORIZ_DIR, 1);
		setcolor(WHITE);
		outtextxy(120, 200, "ID: ");
		outtextxy(150, 200, tmpId);
		outtextxy(120, 220,"Category: ");
		outtextxy(200,220, pdt[0].category);
		outtextxy(120, 240, "Price: ");
		sprintf(price, "%d", pdt[0].price);
		outtextxy(180, 240, price);
		outtextxy(120, 260, "Quantity: ");
		sprintf(quantity, "%d", pdt[0].quantity);
		outtextxy(200, 260, quantity);
		found = 0;
		}
	}
	if(found == 0){
		setcolor(BLACK);
		rectangle(120,h-80, 200, h-60);
		setfillstyle(SOLID_FILL, GREEN);
		floodfill(122, h-76, BLACK);
		outtextxy(126, h-74, "<=Back(x)");
		rectangle(w-200, h-80, w-120, h-60);
		floodfill(w-198, h-78, BLACK);
		outtextxy(w-194, h-74, "Search(z)");
		c= getch();
		if(c =='x'){
			manageStock(1);
		}else if(c =='z'){
			 getProduct();
		}else{
			manageStock(1);
		}
	}else{
	alert();
	settextstyle(0, HORIZ_DIR, 1);
	setcolor(WHITE);
	outtext("Product not found, press any key to go back.");
	getch();
	manageStock(1);
		}
	fclose(fp);
}
void searchByName(){
	 char name[20],price[20],quantity[20],c,countC[20],tmpId[20];
	int w= getmaxx(), h= getmaxy(),height=180,id,end=0,count=0,i=0, perPage;
	struct product pdt[1], pdt1[100];
	FILE *fp;
	cleardevice();
	theme();
	info();
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	outtext("Get Category");
	setcolor(BLACK);
	rectangle(100,130,w-100, h-50 );
	floodfill(110,135, BLACK);
	settextstyle(0, HORIZ_DIR, 1);
	outtextxy(120,145,"Enter Name: ");
	getText(name, 300,145, 20);
	fp = fopen("product.txt", "r");
	if(fp == NULL){
	alert();
	outtext("error");
	return;
	}
	while(fread(&pdt, sizeof(struct product), 1, fp)){
		if(strcmp(pdt[0].name , name) ==0){
			pdt1[count] = pdt[0];
			count++;
		}


	}
	fclose(fp);
	perPage = (((h-100)-180)/38);
	if(count>0){
		sprintf(countC, "%d", count);
		setcolor(WHITE);
		moveto(120,160);
		outtext("Found ");
		setcolor(YELLOW);
		outtext(countC);
		setcolor(WHITE);
		outtext(" products!");
		alert();
		info();

		outtext("Search of : ");
		setcolor(YELLOW);
		outtext(name);
		nextpage:
		if(i>0 && i<count){
			setcolor(BLACK);
			rectangle(280,h-80, 360, h-60);
			setfillstyle(SOLID_FILL, GREEN);
			floodfill(282, h-76, BLACK);
			settextstyle(0, HORIZ_DIR, 1);
			outtextxy(286, h-74, "Prev(a)");
		}
		while(height <= h-100){
			if(i<count){
				settextstyle(0, HORIZ_DIR, 1);
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, WHITE);
				rectangle(150, height, w-150, height+30);
				floodfill(152, height+2, BLACK);
				sprintf(tmpId, "ID: %d", pdt1[i].id);
				outtextxy(155, height+12, tmpId);
				setcolor(MAGENTA);
				outtextxy(215,height+12, pdt1[i].name);
				sprintf(price, "Rs: %d",pdt1[i].price);
				setcolor(GREEN);
				outtextxy(310,height+12,price);
				setcolor(BLACK);
				sprintf(quantity, "QT: %d", pdt1[i].quantity);
				outtextxy(400, height+12, quantity);
				i++;

			}
			height=height+40;

		}
		height=180;
		setcolor(BLACK);
		rectangle(120,h-80, 200, h-60);
		setfillstyle(SOLID_FILL, RED);
		floodfill(122, h-76, BLACK);
		setcolor(WHITE);
		outtextxy(126, h-74, "<=Exit(x)");

		if(i<count){
			setcolor(BLACK);
			rectangle(w-195, h-80, w-120, h-60);
			setfillstyle(SOLID_FILL, GREEN);
			floodfill(w-192, h-78, BLACK);
			outtextxy(w-188, h-74, "Next(d)");
		}
		end=0;
		while(!end){
			c=getch();
			switch(c){
				case 'a':
					if(i> perPage ){
					    if(i> (count -(count % perPage ))){
						 i =  i-(perPage+ (count % perPage));
					    }else{
						i = i- (2 * perPage);
					    }
					    height=180;

					    cleardevice();
					    theme();
					    info();
					    setfillstyle(SOLID_FILL, LIGHTBLUE);
					    setcolor(BLACK);
					    rectangle(100,130,w-100, h-50 );
					    floodfill(110,135, BLACK);
					    outtext("Search of: ");
					    setcolor(YELLOW);
					    outtext(name);
					    setcolor(WHITE);
					    settextstyle(0, HORIZ_DIR, 1);
					    moveto(120,160);
					    outtext("Found ");
					    setcolor(YELLOW);
					    outtext(countC);
					    setcolor(WHITE);
					    outtext(" products!");
					    end =1;
					    goto nextpage;
					}
					break;
				case 'd':
					if(i<count){
					height=180;
					cleardevice();
					theme();
					info();
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					setcolor(BLACK);
					rectangle(100,130,w-100, h-50 );
					floodfill(110,135, BLACK);
					outtext("Search of: ");
					setcolor(YELLOW);
					outtext(name);
					settextstyle(0, HORIZ_DIR, 1);
					setcolor(WHITE);
					moveto(120,160);
					outtext("Found ");
					setcolor(YELLOW);
					outtext(countC);
					setcolor(WHITE);
					outtext(" products!");
					setcolor(BLACK);
					end =1;
					goto nextpage;
					}
					break;
				case 'x':
					end=1;
					getProductMenu(1);
					break;
				default:
					break;

			}
		}







	}else{
		outtextxy(120,155,"0 product found :( ");
		getch();
	}

}
void searchAllProduct(){
	char category[20],price[20],quantity[20],c,countC[20],tmpId[20];
	int w= getmaxx(), h= getmaxy(),height=180,id,end=0,count=0,i=0, perPage;
	struct product pdt[1], pdt1[1000];
	FILE *fp;
	cleardevice();
	theme();
	info();
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	outtext("All Products");
	setcolor(BLACK);
	rectangle(100,130,w-100, h-50 );
	floodfill(110,135, BLACK);
	settextstyle(0, HORIZ_DIR, 1);
	fp = fopen("product.txt", "r");
	if(fp == NULL){
	alert();
	outtext("error");
	return;
	}
	while(fread(&pdt, sizeof(struct product), 1, fp)){
			pdt1[count] = pdt[0];
			count++;
	}
	fclose(fp);
	perPage = (((h-100)-180)/38);
	if(count>0){
		sprintf(countC, "%d", count);

		settextstyle(0, HORIZ_DIR, 1);
		moveto(120,160);
		setcolor(WHITE);
		outtext("Found ");
		setcolor(YELLOW);
		outtext(countC);
		setcolor(WHITE);
		outtext(" product!");
		alert();
		info();

		outtext("All Product");
		nextpage:
		if(i>0 && i<count){
			setcolor(BLACK);
			rectangle(280,h-80, 360, h-60);
			setfillstyle(SOLID_FILL, GREEN);
			floodfill(282, h-76, BLACK);
			settextstyle(0, HORIZ_DIR, 1);
			outtextxy(286, h-74, "Prev(a)");
		}
		while(height <= h-100){
			if(i<count){
				settextstyle(0, HORIZ_DIR, 1);
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, WHITE);
				rectangle(150, height, w-150, height+30);
				floodfill(152, height+2, BLACK);
				sprintf(tmpId, "ID: %d", pdt1[i].id);
				outtextxy(155, height+12, tmpId);
				setcolor(MAGENTA);
				outtextxy(215,height+12, pdt1[i].name);
				sprintf(price, "Rs: %d",pdt1[i].price);
				setcolor(GREEN);
				outtextxy(310,height+12,price);
				setcolor(BLACK);
				sprintf(quantity, "QT: %d", pdt1[i].quantity);
				outtextxy(400, height+12, quantity);
				i++;

			}
			height=height+40;

		}
		height=180;
		setcolor(BLACK);
		rectangle(120,h-80, 200, h-60);
		setfillstyle(SOLID_FILL, RED);
		floodfill(122, h-76, BLACK);
		setcolor(WHITE);
		outtextxy(126, h-74, "<=Exit(x)");

		if(i<count){
			setcolor(BLACK);
			rectangle(w-195, h-80, w-120, h-60);
			setfillstyle(SOLID_FILL, GREEN);
			floodfill(w-192, h-78, BLACK);
			outtextxy(w-188, h-74, "Next(d)");
		}
		end=0;
		sprintf(category , "%d", perPage);
		outtextxy(200,200,category);
		while(!end){
			c=getch();
			switch(c){
				case 'a':
					if(i> perPage ){
					    if(i> (count -(count % perPage ))){
						 i =  (i-(perPage+ (count % perPage)));
					    }else{
						i = (i- (2 * perPage));
					    }

					    height=180;

					    cleardevice();
					    theme();
					    info();
					    setfillstyle(SOLID_FILL, LIGHTBLUE);
					    setcolor(BLACK);
					    rectangle(100,130,w-100, h-50 );
					    floodfill(110,135, BLACK);
					    outtext("All Products");
					    setcolor(WHITE);
					    settextstyle(0, HORIZ_DIR, 1);
					    moveto(120,160);
					    outtext("Found ");
					    setcolor(YELLOW);
					    outtext(countC);
					    setcolor(WHITE);
					    outtext(" product!");
					    end =1;
					    goto nextpage;
					}
					break;
				case 'd':
					if(i<count){
					height=180;
					cleardevice();
					theme();
					info();
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					setcolor(BLACK);
					rectangle(100,130,w-100, h-50 );
					floodfill(110,135, BLACK);
					outtext("All Products");
					    setcolor(WHITE);
					    settextstyle(0, HORIZ_DIR, 1);
					    moveto(120,160);
					    outtext("Found ");
					    setcolor(YELLOW);
					    outtext(countC);
					    setcolor(WHITE);
					    outtext(" product!");
					setcolor(BLACK);
					end =1;
					goto nextpage;
					}
					break;
				case 'x':
					end=1;
					getProductMenu(1);
					break;
				default:
					break;

			}
		}







	}else{
		outtextxy(120,155,"0 product found :( ");
		getch();
		getProductMenu(1);
	}
}
void searchByC(){
	char category[20],price[20],quantity[20],c,countC[20],tmpId[20];
	int w= getmaxx(), h= getmaxy(),height=180,id,end=0,count=0,i=0, perPage;
	struct product pdt[1], pdt1[100];
	FILE *fp;
	cleardevice();
	theme();
	info();
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	outtext("Get Category");
	setcolor(BLACK);
	rectangle(100,130,w-100, h-50 );
	floodfill(110,135, BLACK);
	settextstyle(0, HORIZ_DIR, 1);
	outtextxy(120,145,"Enter Category: ");
	getText(category, 300,145, 20);
	fp = fopen("product.txt", "r");
	if(fp == NULL){
	alert();
	outtext("error");
	return;
	}
	while(fread(&pdt, sizeof(struct product), 1, fp)){
		if(strcmp(pdt[0].category , category) ==0){
			pdt1[count] = pdt[0];
			count++;
		}


	}
	fclose(fp);
	perPage = (((h-100)-180)/38);
	if(count>0){
		sprintf(countC, "%d", count);
		setcolor(WHITE);
		moveto(120,160);
		outtext("Found ");
		setcolor(YELLOW);
		outtext(countC);
		setcolor(WHITE);
		outtext(" products!");
		alert();
		info();

		outtext("Search of : ");
		setcolor(YELLOW);
		outtext(category);
		nextpage:
		if(i>0 && i<count){
			setcolor(BLACK);
			rectangle(280,h-80, 360, h-60);
			setfillstyle(SOLID_FILL, GREEN);
			floodfill(282, h-76, BLACK);
			settextstyle(0, HORIZ_DIR, 1);
			outtextxy(286, h-74, "Prev(a)");
		}
		while(height <= h-100){
			if(i<count){
				settextstyle(0, HORIZ_DIR, 1);
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, WHITE);
				rectangle(150, height, w-150, height+30);
				floodfill(152, height+2, BLACK);
				sprintf(tmpId, "ID: %d", pdt1[i].id);
				outtextxy(155, height+12, tmpId);
				setcolor(MAGENTA);
				outtextxy(215,height+12, pdt1[i].name);
				sprintf(price, "Rs: %d",pdt1[i].price);
				setcolor(GREEN);
				outtextxy(310,height+12,price);
				setcolor(BLACK);
				sprintf(quantity, "QT: %d", pdt1[i].quantity);
				outtextxy(400, height+12, quantity);
				i++;

			}
			height=height+40;

		}
		height=180;
		setcolor(BLACK);
		rectangle(120,h-80, 200, h-60);
		setfillstyle(SOLID_FILL, RED);
		floodfill(122, h-76, BLACK);
		setcolor(WHITE);
		outtextxy(126, h-74, "<=Exit(x)");

		if(i<count){
			setcolor(BLACK);
			rectangle(w-195, h-80, w-120, h-60);
			setfillstyle(SOLID_FILL, GREEN);
			floodfill(w-192, h-78, BLACK);
			outtextxy(w-188, h-74, "Next(d)");
		}
		end=0;
		while(!end){
			c=getch();
			switch(c){
				case 'a':
					if(i> perPage ){
					    if(i> (count -(count % perPage ))){
						 i =  i-(perPage+ (count % perPage));
					    }else{
						i = i- (2 * perPage);
					    }
					    height=180;

					    cleardevice();
					    theme();
					    info();
					    setfillstyle(SOLID_FILL, LIGHTBLUE);
					    setcolor(BLACK);
					    rectangle(100,130,w-100, h-50 );
					    floodfill(110,135, BLACK);
					    outtext("Search of: ");
					    setcolor(YELLOW);
					    outtext(category);
					    setcolor(WHITE);
					    settextstyle(0, HORIZ_DIR, 1);
					    moveto(120,160);
					    outtext("Found ");
					    setcolor(YELLOW);
					    outtext(countC);
					    setcolor(WHITE);
					    outtext(" products!");
					    end =1;
					    goto nextpage;
					}
					break;
				case 'd':
					if(i<count){
					height=180;
					cleardevice();
					theme();
					info();
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					setcolor(BLACK);
					rectangle(100,130,w-100, h-50 );
					floodfill(110,135, BLACK);
					outtext("Search of: ");
					setcolor(YELLOW);
					outtext(category);
					settextstyle(0, HORIZ_DIR, 1);
					setcolor(WHITE);
					moveto(120,160);
					outtext("Found ");
					setcolor(YELLOW);
					outtext(countC);
					setcolor(WHITE);
					outtext(" products!");
					setcolor(BLACK);
					end =1;
					goto nextpage;
					}
					break;
				case 'x':
					end=1;
					getProductMenu(1);
					break;
				default:
					break;

			}
		}







	}else{
		outtextxy(120,155,"0 product found :( ");
		getch();
		getProductMenu(1);
	}
}
void editProduct(){
	char tmpId[20],price[20],quantity[20],c,tmpPrice[20], tmpQt[20];
	int w= getmaxx(), h= getmaxy(),i=10,id,found=1;
	struct product pdt;
	FILE *fp , *fp2;
	cleardevice();
	theme();
	info();
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	outtext("Edit Product");
	setcolor(BLACK);
	rectangle(100,130,w-100, h-50 );
	floodfill(110,135, BLACK);
	settextstyle(0, HORIZ_DIR, 1);
	setcolor(WHITE);
	outtextxy(120,145,"Enter product ID: ");
	getText(tmpId,260,145,20);
	sscanf(tmpId, "%d", &id);
	fp = fopen("product.txt", "r");
	fp2 = fopen("tmp.txt", "w");
	while(fread(&pdt, sizeof(struct product), 1, fp)){
		if(pdt.id == id){
		settextstyle(0, HORIZ_DIR, 2);
		setcolor(YELLOW);
		outtextxy(120,180, pdt.name);
		settextstyle(0, HORIZ_DIR, 1);
		setcolor(WHITE);
		outtextxy(120, 200, "ID: ");
		outtextxy(150, 200, tmpId);
		outtextxy(120, 220, "Price: ");
		sprintf(price, "%d", pdt.price);
		outtextxy(180, 220, price);
		outtextxy(120, 240, "Quantity: ");
		sprintf(quantity, "%d", pdt.quantity);
		outtextxy(200, 240, quantity);
		found = 0;

		line( 110, 250, w-110, 250);
	       //	pdt.id = id;
		outtextxy(120, 280, "Product name: ");
		getText(pdt.name, 260, 280,20);
		outtextxy(120, 300,"Price(each): ");
		getText(tmpPrice, 260, 300, 20);
		sscanf(tmpPrice, "%d", &pdt.price);
		outtextxy(120, 320, "Quantity: ");
		getText(tmpQt, 260, 320, 20);
		sscanf(tmpQt, "%d", &pdt.quantity);

		}
		fwrite(&pdt, sizeof(pdt), 1, fp2);
	}
	fclose(fp);
	fclose(fp2);
	if(found == 0){
		    fp2 = fopen("tmp.txt", "r");
		    fp = fopen("product.txt", "w");
		    while(fread(&pdt, sizeof(pdt), 1, fp2)){
			fwrite(&pdt, sizeof(pdt), 1, fp);
		    }
		    fclose(fp);
		    fclose(fp2);

		alert();
		info();
		outtext("Edit successful!");
		settextstyle(0, HORIZ_DIR, 1);
		setcolor(BLACK);
		rectangle(120,h-80, 200, h-60);
		setfillstyle(SOLID_FILL, GREEN);
		floodfill(122, h-76, BLACK);
		outtextxy(126, h-74, "<=Back(x)");
		rectangle(w-200, h-80, w-120, h-60);
		floodfill(w-198, h-78, BLACK);
		outtextxy(w-194, h-74, "Edit(z)");
		c= getch();
		if(c =='x'){
			manageStock(1);
		}else if(c =='z'){
			 editProduct();
		}else{
			manageStock(1);
		}
	}else{
	alert();
	settextstyle(0, HORIZ_DIR, 1);
	setcolor(WHITE);
	outtext("Product not found, press any key to go back.");
	getch();
	manageStock(1);
	}

}
void deleteProduct(){
	char tmpId[20],price[20],quantity[20],c,c1;
	int w= getmaxx(), h= getmaxy(),i=10,id,found=1;
	struct product pdt[1];
	FILE *fp, *fp1;
	cleardevice();
	theme();
	info();
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	outtext("Get Product");
	setcolor(BLACK);
	rectangle(100,130,w-100, h-50 );
	floodfill(110,135, BLACK);
	settextstyle(0, HORIZ_DIR, 1);
	setcolor(WHITE);
	outtextxy(120,145,"Enter product ID: ");
	getText(tmpId,260,145,20);
	sscanf(tmpId, "%d", &id);
	fp = fopen("product.txt", "r");
	while(fread(&pdt, sizeof(struct product), 1, fp)){
		if(pdt[0].id == id){
		settextstyle(0, HORIZ_DIR, 2);
		setcolor(YELLOW);
		outtextxy(120,180, pdt[0].name);
		settextstyle(0, HORIZ_DIR, 1);
		setcolor(WHITE);
		outtextxy(120, 200, "ID: ");
		outtextxy(150, 200, tmpId);
		outtextxy(120, 220, "Price: ");
		sprintf(price, "%d", pdt[0].price);
		outtextxy(180, 220, price);
		outtextxy(120, 240, "Quantity: ");
		sprintf(quantity, "%d", pdt[0].quantity);
		outtextxy(200, 240, quantity);
		found = 0;
		}
	}
	fclose(fp);
	if(found == 0){
		setcolor(BLACK);
		rectangle(120,h-80, 200, h-60);
		setfillstyle(SOLID_FILL, GREEN);
		floodfill(122, h-76, BLACK);
		outtextxy(126, h-74, "<=Back(x)");
		rectangle(280,h-80, 360, h-60);
		setfillstyle(SOLID_FILL, RED);
		setcolor(WHITE);
		floodfill(282, h-76, BLACK);
		outtextxy(286, h-74, "DELETE(D)");
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, GREEN);
		rectangle(w-200, h-80, w-120, h-60);
		floodfill(w-198, h-78, BLACK);
		outtextxy(w-194, h-74, "Search(z)");
		c= getch();
		if(c =='x'){
			manageStock(1);
		}else if(c =='z'){
			 deleteProduct();
		} else if(c =='d'){
			alert();
			settextstyle(0, HORIZ_DIR, 1);
			outtext("Are you sure you want to delete this product?(y/n)");
			c1 = getch();
			if(c1 =='n'){
				manageStock(1);
			}else{
				fp = fopen("product.txt", "r");
				fp1 = fopen("temp.txt", "w");
				while(fread(&pdt, sizeof(pdt), 1, fp)){
					if(pdt[0].id != id){
						fwrite(&pdt, sizeof(pdt), 1, fp1);
					}
				}
				fclose(fp);
				fclose(fp1);

				fp = fopen("temp.txt", "r");
				fp1 = fopen("product.txt", "w");
				while(fread(&pdt, sizeof(pdt), 1, fp)){
					fwrite(&pdt, sizeof(pdt), 1, fp1);
				}
				fclose(fp);
				fclose(fp1);
				info();
				outtext("Delete successful!");
				getch();
				manageStock(1);
			}
		}
		else{
			manageStock(1);
		}
	}else{
	alert();
	settextstyle(0, HORIZ_DIR, 1);
	setcolor(WHITE);
	outtext("Product not found, press any key to go back.");
	getch();
	manageStock(1);
		}
}

void changePass(){
	FILE *fp;
	struct user usr[1];
	int checkPw, w = getmaxx(), h=getmaxy(),passPos1=0, passPos=0,end=0, end1=0;
	char password[20],password2[20],p, cpassword[20], cpassword2[20];
	checkPw = askPassword();
	if(checkPw == 0){
		cleardevice();
		theme();
		setcolor(GREEN);
		rectangle(70, 150, w-70, 300);
		outtextxy(90, 170, "Change Password");
		setcolor(BLACK);
		settextstyle(0, HORIZ_DIR, 1);
		outtextxy(90, 210, "New Password:");
		password[0]=0;
		password2[0]=0;
		do{
			outtextxy(210,210, password);
			p= getch();
			switch(p){
				case 8:
					if(passPos){
					passPos--;
					password[passPos]=0;
					password2[passPos] =0;
					}
					break;
				case 13:
					end=1;
					break;
				case 27:
					password[0] = 0;
					password2[0] = 0;
					end =1;
					break;
				default:
					if(passPos < 19 && p>= ' ' && p <= '~' ){
					password[passPos] = '*';
					password2[passPos] = p;
					passPos++;
					password[passPos] = 0;
					password2[passPos] = 0;
					}

			}
		}while(!end);
		outtextxy(90, 230, "Confirm Password:");
		cpassword[0]=0;
		cpassword2[0]=0;
		do{
			outtextxy(250,230, cpassword);
			p= getch();
			switch(p){
				case 8:
					if(passPos1){
					passPos1--;
					password[passPos1]=0;
					password2[passPos1] =0;
					}
					break;
				case 13:
					end1=1;
					break;
				case 27:
					cpassword[0] = 0;
					cpassword2[0] = 0;
					end1 =1;
					break;
				default:
					if(passPos1 < 19 && p>= ' ' && p <= '~' ){
					cpassword[passPos1] = '*';
					cpassword2[passPos1] = p;
					passPos1++;
					cpassword[passPos1] = 0;
					cpassword2[passPos1] = 0;
					}

			}
		}while(!end1);
		if(strcmp(cpassword2, password2) == 0){
			fp = fopen("password.bin","rb");
			fread(&usr, sizeof(struct user), 1, fp);
			fclose(fp);
			strcpy(usr[0].password, password2);
			fp = fopen("password.bin","wb");
			fwrite(usr, sizeof(struct user),1, fp);
			fclose(fp);
			info();
			outtext("Change Success!");
			getch();
			menu(1);
		}else{
			alert();
			setcolor(WHITE);
			outtext("Not Matched!");
			getch();
			menu(1);
		}
		//outtextxy(200,200,  cpassword2);
		getch();

	}else if(checkPw == 1){
		alert();
		outtext("Wrong Password!");
		getch();
		menu(1);
	}else{
	alert();
	outtext("Something went wrong!");
	getch();
	menu(1);
	}

}