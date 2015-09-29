typedef struct books
{
    int id;
    char name[20];
    char author[20];
    int quantity;
    float price;
    int rackno;
    char cat[20];
    char subcat[20];
}Book;
Book book;
enum Genres {FICTION = 1, NONFICTION, REFERENCE, SELFHELP};
void mainmenu();
void addentry();
void printentry();
void printgenres();
void printfiction();
void printref();
void printselfhelp();
void deleteentry();
void editentry();
void searchentry();
void issuebooks();
void returnbook();
void viewbooks();
void closeapplication();
int  getdata();
int  checkid(int);
int t();
void Password();

