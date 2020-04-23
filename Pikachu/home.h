#pragma once

int q_color = 10;// mau cua cau hoi
int a_color = 14;// mau cau tra loi
int n_color = 12;// mau ghi chu
int color = 15;// mau chu hien thi
int S = 1;// bien dieu khien trinh chieu =1 trinh chieu =0 an trinh chieu
int V = 200;// toc do trinh chieu cang lon cang cham
int F = 0;// mac dinh bang 0 bang 1 nhap F tu ban phim
int loop = 0;//hoat dong hinh anh
int A = 1;// bat tat am thanh
int D = 1;//delay o moi buoc
void Setup()//ham tao ra cac gia tri ban dau duoc chay dau tien
{
    ancontro();
    
    setcolor(color);
    int a;
    ifstream data;
    data.open("E:\\Project_C-2plus\\Pikachu\\setting\\setup.set", ios::in);
    data >> S;
    data >> V;
    data >> F;
    data >> A;
    data >> D;
    data.close();
}
void note(char* note)
{
    int x = wherex();
    int y = wherey();

    gotoxy(0, 0);
    vout << note;
    gotoxy(x, y);
}
int inp(int a, int b)
{
    setcolor(a_color);
    int x = wherex();
    int y = wherey();
    int n;
    while (1)
    {
        gotoxy(x, y);
        cin >> n;
        if (n<a || n>b)
        {
            gotoxy(x, y);
            cout << "                    ";
            
        }
        else
        {
            if (A == 1)
                Beep(1700, 50);
            return n;
        }
    }


}
void Delay(int x, int y)
{
    while (1)
    {
        gotoxy(x, y); setcolor(9);
        
        Sleep(200);
        gotoxy(x, y); setcolor(1);
        
        Sleep(200);
        if (kbhit())
        {
            char a = getch();
            if (kbhit()) a = getch();
            if (A == 1)
                Beep(900, V / 2);
            break;
        }
    }
}

///---dieu khien man hinh va cac doi tuong---///
void Amination(char* name)
{

    int x = wherex(), y = wherey();
    int sl_img, sl_col, sl_row;
    int sl_color, color[10], ascii[10], col;
    gotoxy(x, y);
    char amina[30] = " ";
    strcpy(amina, "E:\\Project_C-2plus\\Pikachu\\ascii_img");
    strcat(amina, name);
    strcat(amina, "/_.txt");
    amina[12] = 48;

    ifstream p;
    p.open(amina, ios::in);
    p >> sl_img;

    p >> sl_col;
    p >> sl_row;
    p >> sl_color;

    for (int i = 0;i < sl_color;i++)
    {
        p >> color[i];
        p >> ascii[i];
    }
    p >> col;
    p.close();

    amina[12] = 49 + loop;
    gotoxy(x, y);
    ////////////////////////////////
    int x1 = wherex();
    int y1 = wherey();
    ifstream image;
    image.open(amina, ios::in);
    char ch;
    for (int i = 0;i < sl_col;i++)
    {
        gotoxy(x1, y1++);

        for (int j = 0;j < sl_row;j++)
        {
            image >> ch;
            setcolor(col);
            for (int k = 0;k < sl_color;k++)
            {
                if (ch == ascii[k])
                {
                    setcolor(color[k]);
                }
            }
            cout << ch;
        }
    }
    image.close();
    ////////////////////////////////
    if (loop >= sl_img - 1) loop = 0;
    else loop++;

}
void Khung(int x, int y, int wi, int he, int color)
{
    setcolor(color);
    int i = 0, j = 0, dung1 = 0, dung2 = 0;
    while (1)
    {
        if (dung1 == 0)
        {
            gotoxy(++i + x, y);
            cout << char(196);
            gotoxy(i + x, y + he - 1);
            cout << char(196);
            if (i == wi - 2) dung1 = 1;
        }


        if (dung2 == 0)
        {
            gotoxy(x, ++j + y);
            cout << char(179);
            gotoxy(x + wi - 1, j + y);
            cout << char(179);
            if (j == he - 2) dung2 = 1;
        }
        if (dung1 == 1 && dung2 == 1) break;
    }
    gotoxy(x, y); cout << char(218);
    gotoxy(x, y + he - 1);cout << char(192);
    gotoxy(x + wi - 1, y); cout << char(191);
    gotoxy(x + wi - 1, y + he - 1); cout << char(217);

}
void KhungDouble(int x, int y, int wi, int he, int color)
{
    setcolor(color);
    int i = 0, j = 0, dung1 = 0, dung2 = 0;
    while (1)
    {
        if (dung1 == 0)
        {
            gotoxy(++i + x, y);
            cout << char(205);
            gotoxy(i + x, y + he - 1);
            cout << char(205);
            if (i == wi - 2) dung1 = 1;
        }


        if (dung2 == 0)
        {
            gotoxy(x, ++j + y);
            cout << char(186);
            gotoxy(x + wi - 1, j + y);
            cout << char(186);
            if (j == he - 2) dung2 = 1;
        }
        if (dung1 == 1 && dung2 == 1) break;
    }
    gotoxy(x, y); cout << char(201);
    gotoxy(x, y + he - 1);cout << char(200);
    gotoxy(x + wi - 1, y); cout << char(187);
    gotoxy(x + wi - 1, y + he - 1); cout << char(188);
}
int Menu()
{
    float dk;
    int re = 1, green = 10, blue = 1, page = 0;
    while (1)
    {
        KhungDouble(0, 0, 80, 24, green);
        KhungDouble(1, 1, 78, 22, blue);
        Khung(2, 2, 76, 20, 7);
        KhungDouble(10, 3, 60, 5, 12);
        gotoxy(25, 5);setcolor(14);
        
        ///-----Phan Lua Chon------/////
                /////////////////////////////////////////

        if (page == 0)
        {
            if (re > 3) re = 3;
            if (re < 1) re = 1;
            gotoxy(42, 9);
            setcolor(10);
            
            Khung(10, 8, 21, 9, 8);
            gotoxy(19, 8);setcolor(15);
            cout << "1/3";
            gotoxy(13, 10); if (re == 1)setcolor(10); else setcolor(8);
            
            gotoxy(13, 12); if (re == 2)setcolor(10); else setcolor(8);
            
            gotoxy(13, 14); if (re == 3)setcolor(10); else setcolor(8);
            
        }
        if (page == 1)
        {
            if (re > 5) re = 5;
            if (re < 1) re = 1;
            gotoxy(45, 9);
            setcolor(9);
            
            Khung(10, 8, 21, 13, 8);
            gotoxy(19, 8);setcolor(15);
            cout << "2/3";
            gotoxy(13, 10); if (re == 1)setcolor(9); else setcolor(8);
            
            gotoxy(13, 12); if (re == 2)setcolor(9); else setcolor(8);
            
            gotoxy(13, 14); if (re == 3)setcolor(9); else setcolor(8);
            
            gotoxy(13, 16); if (re == 4)setcolor(9); else setcolor(8);
            
            gotoxy(13, 18); if (re == 5)setcolor(9); else setcolor(8);
            
        }
        if (page == 2)
        {
            if (re > 2) re = 2;
            if (re < 1) re = 1;
            Khung(10, 8, 21, 7, 8);
            gotoxy(19, 8);setcolor(15);
            cout << "3/3";
            gotoxy(13, 10); if (re == 1)setcolor(15); else setcolor(8);
            
            gotoxy(13, 12); if (re == 2)setcolor(15); else setcolor(8);
            
        }
        ///-----bat su kien ban phim
        if (kbhit())
        {
            char select = getch();
            if (kbhit()) { select = getch(); }
            if (select == 80)
            {
                if (A == 1)
                    Beep(1850, 100);
                re++;
            }
            if (select == 72)
            {
                re--;
                if (A == 1)
                    Beep(1000, 100);
            }
            if (select == 13)
            {
                clrscr();
                return page * 5 + re;
            }
            if (select == 77)
            {
                if (A == 1) Beep(2000, 150);
                if (page != 2)
                    page++;
                else
                    page = 0;
                re = 1;
                clrscr();
            }
            if (select == 75)
            {
                if (A == 1) Beep(1500, 150);
                if (page != 0)
                    page--;
                else
                    page = 2;
                re = 1;
                clrscr();
            }


        }

        Khung(31, 8, 37, 12, 4);
        ///////////////////////////////////////
        ///----info----///

        
        for (int k = 1;k <= 15;k++)
        {
            gotoxy(33 + k * 2, 17);
            setcolor(k);
            cout << (char)219;
        }
        ///////////////////////////////////////
        if (green == 10) green = 2;
        else green = 10;
        if (blue == 1) blue = 9;
        else blue = 1;
    }
}

void Setting()
{
    KhungDouble(0, 0, 80, 24, 12);
    int sel = 1;
    while (1) {
        Khung(1, 1, 29, 7, 10);
        gotoxy(12, 4);setcolor(14);
        
        KhungDouble(2, 3, 27, 3, 4);

        Khung(1, 8, 29, 15, 15);
        gotoxy(3, 10);setcolor(q_color);
        
        if (S == 1)
            setcolor(15);
        else
            setcolor(0);
        cout << (char)219;

        gotoxy(3, 12);setcolor(q_color);
        
        int vec = V / 50;setcolor(15);
        for (int i = 0;i < vec;i++)
        {
            gotoxy(18 + i, 12);
            cout << (char)219 << " ";
        }

        gotoxy(3, 14);setcolor(q_color);
        
        if (F == 1)
            setcolor(15);
        else
            setcolor(0);
        cout << (char)219;

        gotoxy(3, 16);setcolor(q_color);
        
        if (A == 1)
            setcolor(15);
        else
            setcolor(0);
        cout << (char)219;

        gotoxy(3, 18);setcolor(q_color);
        
        if (D == 1)
            setcolor(15);
        else
            setcolor(0);
        cout << (char)219;

        setcolor(12);
        Khung(2, 7 + sel * 2, 27, 3, 12);

        char* p;
        gotoxy(33, 4);
        if (S == 1)
            Amination("p");

        if (A == 1) {
            if (loop == 1 && A == 1)
                Beep(1800, 40);
            if (loop == 2 && A == 1)
                Beep(2800, 60);
            if (loop == 3 && A == 1)
                Beep(2300, 80);
        }
        if (kbhit())
        {

            char select = getch();
            if (kbhit()) select = getch();
            if (select == 80 && sel < 5)
            {
                Khung(2, 7 + sel * 2, 27, 3, 0);
                sel++;
                if (A == 1)
                    Beep(950, 100);
            }
            if (select == 72 && sel > 1)
            {
                Khung(2, 7 + sel * 2, 27, 3, 0);
                sel--;
                if (A == 1)
                    Beep(1100, 100);
            }
            if (select == 77)
            {
                if (sel == 1)
                    S = !S;
                if (sel == 3)
                    F = !F;
                if (sel == 2 && V < 500)
                {
                    V += 50;
                }
                if (sel == 4)
                    A = !A;
                if (sel == 5)
                    D = !D;
                if (A == 1)
                    Beep(1500, 100);
            }
            if (select == 75)
            {
                if (sel == 1)
                    S = !S;
                if (sel == 3)
                    F = !F;
                if (sel == 2 && V > 50)
                {
                    V -= 50;
                }
                if (sel == 4)
                    A = !A;
                if (sel == 5)
                    D = !D;
                if (A == 1)
                    Beep(800, 100);
            }
            if (select == 13)
            {
                clrscr();
                ofstream data;
                data.open("setting/setup.set", ios::trunc);
                data << S << endl << V << endl << F << endl << A << endl << D;
                data.close();
                if (A == 1)
                    Beep(1200, 100);
                break;
            }
        }
    }
}
void Logo_CPP()
{
    Beep(2900, 80);
    Beep(2900, 80);
    gotoxy(24, 4);
    Amination("a");
    Sleep(500);
    Khung(2, 1, 74, 22, 10);
    Beep(2500, 500);
    clrscr();
    if (S == 1)
    {
        if (A == 1) {
            Beep(2800, 60);
            Beep(2900, 80);
        }
        gotoxy(21, 7);
        Amination(char*"l");
        KhungDouble(0, 0, 80, 24, 9);
        Khung(2, 1, 76, 22, 1);
        if (A == 1)
            Beep(1800, 500);
        Sleep(500);
        clrscr();
        for (int i = 2;i < 38;i += 2)
        {
            KhungDouble(0, 0, 80, 24, 14);
            gotoxy(i, 5);
            Amination("p");
            if (loop == 1 && A == 1)
                Beep(1800, 40);
            if (loop == 2 && A == 1)
                Beep(2800, 60);
            if (loop == 3 && A == 1)
                Beep(2300, 80);
        }
        clrscr();
        Sleep(200);
    }
}
bool SetWindowSize(size_t width, size_t height)
{
    HANDLE output_handle = ::GetStdHandle(STD_OUTPUT_HANDLE);
    if (output_handle == INVALID_HANDLE_VALUE)
        return false;

    COORD coord = {};
    coord.X = static_cast<SHORT>(width);
    coord.Y = static_cast<SHORT>(height);
    if (::SetConsoleScreenBufferSize(output_handle, coord) == FALSE)
        return false;

    SMALL_RECT rect = {};
    rect.Bottom = coord.X - 1;
    rect.Right = coord.Y - 1;
    return (::SetConsoleWindowInfo(output_handle, TRUE, &rect) != FALSE);
}
