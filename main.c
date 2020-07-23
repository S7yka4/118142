#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct sentence
{
    char* fild;
    struct sentence* next;
};

struct text
{
    struct sentence* fild;
    struct text* next;
    struct text* prev;
};

struct textbook
{
    struct text* fild;
    struct textbook* next;
    int kount;
    int border;
};

void showword(char *source)
{
    int i=0;
    if(source!=NULL)
    do
    {
        if(source[i]!='\n')
            putchar(source[i]);
        i++;
    }while(source[i]!='\n');

}

char* makeword()
{
    char *res;
    char lit;
    int i=0;
    printf("Vvedite slovo\n");
    res=(char*)malloc(sizeof(char));
    getchar();
    do
    {
        lit=getchar();
        res[i]=lit;
        res=(char*)realloc(res,(i+2)*sizeof(char));
        i++;
    }while(res[i-1]!='\n');
    return res;
}



bool svoidcheck(struct sentence* root)
{
if((root->next==NULL)&&(root->fild==NULL))
return true;
else
return false;
}

void showsentence(struct sentence* source, struct sentence* root)
{
struct sentence *res;
if(root!=NULL)
{
if(!svoidcheck(root))
{
res=root;
do
{
if(res==source)
printf("!");
if(res->fild!=NULL)
    showword(res->fild);
if(res==source)
printf("!");
if(res->fild!=NULL)
    printf(" ");
res=res->next;
}while(res!=NULL);
}
else
    printf("Spisok slov pust");
}
}

struct sentence* initsentence()
{
    struct sentence* res;
    res=(struct sentence*)malloc(sizeof(struct sentence));
    res->next=NULL;
    res->fild=NULL;
    return res;
}

struct sentence* smovebackward(struct sentence* source, struct sentence*root)
{
while(root->next!=source)
root=root->next;
return root;
}

bool sendcheck(struct sentence* source)
{
if(source->next==NULL)
return true;
else
return false;
}

struct sentence* smovetoroot(struct sentence* root)
{
showsentence(root,root);
return root;
}

struct sentence* smovetoend(struct sentence* source)
{
while(source->next!=NULL)
source=source->next;
return source;
}

struct sentence* smoveforward(struct sentence* source, struct sentence* root)
{
if(!sendcheck(source))
{
source=source->next;
showsentence(source,root);
return source;
}
else
{
printf("ERR:vy nahodytes v konce spiska\n");
return source;
}
}

struct sentence* sdelition(struct sentence* source, struct sentence* root)
{
struct sentence*res;
if(source!=root)
{
res=smovebackward(source,root);
res->next=source->next;
source->next=NULL;
free(source);
return res;
}
else

if(root->next!=NULL)
{
res=root->next;
root->next=NULL;
free(root);
return res;
}
}

struct sentence* sclean(struct sentence* source, struct sentence* root)
{
struct sentence* res;
res=smovetoend(source);
while(res!=root)
res=sdelition(res,root);
res->fild=NULL;
printf("Spisok slov ochishen\n");
return res;
}

void snextelemshow(struct sentence* source)
{
if(!sendcheck(source))
{
source=source->next;
showword(source->fild);
}
else
printf("ERR:vy nahodytes v konce spiska ili spisok pust\n");
}

void snextelemdelition(struct sentence* source,struct sentence* root)
{
if(!svoidcheck(source))
{
source=sdelition(source->next,root);
showsentence(source,root);
}
else
printf("ERR:vy nashodites v konce spiska ili spisok pust\n");
}

struct word* snextelemtake(struct sentence* source)
{
if(!svoidcheck(source))
{
source=source->next;
return source->fild;
}
else
{
printf("ERR:vy nashodites v konce spiska ili spisok pust\n");
return NULL;
}
}

void snextelemchange(struct sentence* source, struct sentence* root)
{
struct sentence* res;
if(!sendcheck(source))
{
res=source->next;
res->fild=makeword();
showsentence(source,root);
}
else
printf("ERR:vy nashodites v konce spiska ili spisok pust\n");
}

void sadd(struct sentence* source, struct sentence* root)
{
    struct sentence *res,*tmp;
    char point[1000];
    if(!svoidcheck(source))
    {
        res=(struct sentence*)malloc(sizeof(struct sentence));
        res->fild=makeword();
        if(sendcheck(source))
        {
            res->next=NULL;
            source->next=res;
            showsentence(source,root);
        }
        else
        {
            tmp=source->next;
            res->next=tmp;
            source->next=res;
            showsentence(source,root);
        }
    }
    else
    {
        printf("Vy nahodytes v pustom spiske spiske\n");
        printf("Hotite nachat zapolnyat pustoy spisok?\n");
        printf("Da-1                             Net-2\n");
        scanf("%s",point);
        if(atoi(point)==1)
        {
            source->fild=makeword();
            showsentence(source,root);
            return 0;
        }
        else
            if(atoi(point)==2)
            {
                printf("Vozvrashenye v menu\n");
                return 0;
            }
            else
            {
                printf("ERR:nekorrektnyi vvod\n");
                printf("Vozvrashenye v menu\n");
                return 0;
            }
    }
}

struct sentence* stopworkingonlist( struct sentence*root)
{
    printf("zavershenye raboty\n");
    return root;
}

struct sentence* movetosentence(struct sentence* root)
{
    struct sentence *c;
    char *b,point[1000];
    bool flag=false;
    point[0]='\0';
    c=root;
    while(atoi(point)!=13)
    {
        printf("\n");
        printf("!1.Nachalo raboty-1!\n");
        printf("!2.Ochistka spiska-2!\n");
        printf("!3.Proverka spiska na pustotu-3!\n");
        printf("!4.Ustanovka ukazatelya v nachalo spiska-4!\n");
        printf("!5.Proverka dostigenia konca spiska-5!\n");
        printf("!6.Peredvizhenie ukazatelya vpered-6!\n");
        printf("!7.Vyvod sleduyushego elementa-7!\n");
        printf("!8.Udalenye sleduyushego elementa-8!\n");
        printf("!9.Vzyatie znachenya sleduyushego elementa-9!\n");
        printf("!10.Izmenenye znachenya sleduyushego elementa-10!\n");
        printf("!11.Dobavlenye elementa-11!\n");
        printf("!12.Vyvod spiska na ekran-12!\n");
        printf("!13.Konec raboty so spiskom-13!\n");
        printf("!14.Avaryinoe zavershenye raboty-14\n!");
        printf("Vvedite chislo\n");
        scanf("%s",point);
        if((atoi(point))&&(atoi(point)<=14)&&(atoi(point)>=1))
        {
            if((atoi(point)==1))
            {
                if(flag!=true)
                {
                    flag=1;
                    printf("Spisok slov initializirovan\n");
                }
                else
                    printf("Spisok uzhe byl inizializirovan\n");
            }
            if((atoi(point)==2)&&(flag))
            {
                root=sclean(c,root);
                c=smovetoroot(root);
            }
            if((atoi(point)==3)&&(flag))
                if(svoidcheck(root))
                    printf("spisok pust\n");
                else
                    printf("spisok ne pust\n");
            if((atoi(point)==4)&&(flag))
                c=smovetoroot(root);
            if((atoi(point)==5)&&(flag))
                if(sendcheck(c))
                    printf("konec dostignut\n");
                else
                    printf("konec ne dostignut\n");
            if((atoi(point)==6)&&(flag))
                c=smoveforward(c,root);
            if((atoi(point)==7)&&(flag))
                snextelemshow(c);
            if((atoi(point)==8)&&(flag))
                snextelemdelition(c,root);
            if((atoi(point)==9)&&(flag))
            {
                b=snextelemtake(c);
                showword(b);
            }
            if((atoi(point)==10)&&(flag))
            {
               snextelemchange(c,root);
            }
            if((atoi(point)==11)&&(flag))
            {
                sadd(c,root);
            }
            if((atoi(point)==12)&&(flag))
                showsentence(c,root);
            if((atoi(point)==13)&&(flag))
            {
                flag=true;
                return stopworkingonlist(root);
            }
            if((atoi(point)==14))
                exit(0);
            if(flag!=true)
                printf("ERR:Nachnite rabotu so spiskom\n");
        }
        else
            printf("ERR:Nekorrektnyi vvod\n");
    }
return NULL;
}



struct text* textmovetoend(struct text*source)
{
struct text*res;
res=source;
while(res->next!=NULL)
res=res->next;
return res;
}

struct text* textmovetoroot(struct text*source)
{
struct text*res;
res=source;
while(res->prev!=NULL)
res=res->prev;
return res;
}

bool textvoidcheck(struct text*source)
{
if((source->fild==NULL)&&(source->next==NULL)&&(source->prev==NULL))
return true;
else
return false;
}

void showtextreversed(struct text*source)
{
struct text*res;
if(!textvoidcheck(source))
{
res=textmovetoend(source);
printf("\n");
do
{
if(res==source)
printf("!");
if(res->fild!=NULL)
{
    showsentence(NULL,res->fild);
    if(res==source)
        printf("!");
    printf("\n");
}
res=res->prev;
}while(res!=NULL);
printf("\n");
}
else
    printf("Spisok pust\n");
}

struct text* delsentence(struct text*source)
{
struct text*res,*temp;
if((source->next!=NULL)&&(source->prev!=NULL))
{
res=source->prev;
res->next=source->next;
temp=source->next;
temp->prev=res;
source->next=NULL;
source->prev=NULL;
free(source);
return res;
}
if((source->next==NULL)&&(source->prev!=NULL))
{
res=source->prev;
res->next=NULL;
source->prev=NULL;
free(source);
return res;
}
if (source->prev==NULL)
{
if (source->next==NULL)
{
source->fild=NULL;
}
else
{
res=source->next;
res->prev=NULL;
source->next=NULL;
free(source);
return res;
}
}
}

struct text* cleantext(struct text*source)
{
struct text*res;
res=source;
    while(res->next!=NULL)
        res=res->next;
    while(res->prev!=NULL)
        res=delsentence(res);
    free(res);
    res=(struct textbook*)malloc(sizeof(struct textbook));
    res->fild=NULL;
    res->next=NULL;
    res->prev=NULL;
    printf("Spisok ochishen\n");
    return res;
}

bool textrootcheck(struct text* source)
{
if((source->prev==NULL))
return true;
else
return false;
}

bool textendcheck(struct text* source)
{
if((source->next==NULL))
return true;
else
return false;
}

struct text* textmoveforward(struct text*source)
{
if(!textendcheck(source))
{
showtext(source->next);
return source->next;
}
else
{
printf("ERR:vy nahodites v konce spiska\n");
return source;
}
}

struct text* textmovebackward (struct text* source)
{
if(!textrootcheck(source))
{
showtext(source->prev);
return source->prev;
}
else
{
printf("ERR:vy nahodites v nachale spiska\n");
return source;
}
}

void textprevelemshow(struct text*source)
{
struct text* res;
if (!textrootcheck(source))
{
res=source->prev;
showsentence(NULL,res->fild);
}
else
printf("ERR:spisok pust ili sostoit iz odnogo elementa\n");
}

void textnextelemshow(struct text*source)
{
struct text*res;
if(!textendcheck(source))
{
res=source->next;
showsentence(NULL,res->fild);
}
else
printf("ERR:spisok pust ili sostoit iz odnogo elementa\n");
}

struct text* textprevelemdel(struct text*source)
{
struct text* res;
if(!textrootcheck(source))
{
res=source->prev;
res=delsentence(res);
showtext(res);
return res;
}
else
{
printf("ERR:spisok pust ili sostoit iz odnogo elementa\n");
return source;
}
}

struct text* textnextelemdel(struct text*source)
{
struct text*res;
if(!textendcheck(source))
{
res=source->next;
res=delsentence(res);
showtext(res);
return res;
}
else
{
printf("ERR:spisok pust ili sostoit iz odnogo elementa\n");
return source;
}
}

struct sentence* textprevelemtake(struct text*source)
{
struct text*res;
if(!textrootcheck(source))
{
res=source->prev;
return res->fild;
}
else
{
printf("ERR:spisok pust ili sostoit iz odnogo elementa\n");
return NULL;
}
}

struct sentence* textnextelemtake(struct text*source)
{
struct text*res;
if(!textendcheck(source))
{
res=source->next;
return res->fild;
}
else
{
printf("ERR:spisok pust ili sostoit iz odnogo elementa\n");
return NULL;
}
}

struct text* inittext()
{
    struct text *res;
    res=(struct text*)malloc(sizeof(struct text));
    res->next=NULL;
    res->prev=NULL;
    res->fild=NULL;
    return res;
}

void showtext(struct text*source)
{
struct text*res;
res=source;
if(res!=NULL)
{
if(!textvoidcheck(source))
{
while(res->prev!=NULL)
    res=res->prev;
do
{
if(res==source)
printf("!");
if(res->fild!=NULL)
    showsentence(NULL,res->fild);
if(res==source)
printf("!");
if(res->fild!=NULL)
    printf("\n");
res=res->next;
}while(res!=NULL);
}
else
    printf("Spisok pust\n");
}
}

void textprevelemchange(struct text* source)
{
    if(!textrootcheck(source))
    {
        printf("Perehod k spisku slov\n");
        source=source->prev;
        source->fild=movetosentence(source->fild);
        source=source->next;
        showtext(source);
        showtextreversed(source);
    }
    else
        printf("ERR:spisok pust ili sostoit iz odnogo elementa\n");
}

void textnextelemchange(struct text* source)
{
    if(!textendcheck(source))
    {
        printf("Perehod k spisku slov\n");
        source=source->next;
        source->fild=movetosentence(source->fild);
        source=source->prev;
        showtext(source);
        showtextreversed(source);
    }
    else
        printf("ERR:spisok pust ili sostoit iz odnogo elmenta\n");
}

void textprevelemadd(struct text* source)
{
    struct text* res;
    char point[1000];
    if(!textvoidcheck(source))
    {
        res=(struct text*)malloc(sizeof(struct text));
        if(source->prev!=NULL)
        {
            res->next=source;
            res->prev=source->prev;
            source=source->prev;
            source->next=res;
            source=res->next;
            source->prev=res;
        }
        else
        {
            res->prev=NULL;
            res->next=source;
            source->prev=res;
        }
        printf("perehod k spisku slov\n");
        res->fild=initsentence();
        res->fild=movetosentence(res->fild);
        showtext(source);
        showtextreversed(source);
    }
    else
    {
        printf("Vy nahodites v pustom spiske\n");
        printf("Nachat zapolnenye spiska?\n");
        printf("Da-1                Net-2\n");
        scanf("%s",point);
        if(atoi(point)==1)
        {
            printf("perehod k spisku slov\n");
            source->fild=initsentence();
            source->fild=movetosentence(source->fild);
            showtext(source);
            showtextreversed(source);
            return 0;
        }
        else
            if(atoi(point)==2)
            {
                printf("Vozvrashenye v menu\n");
                return 0;
            }
            else
            {
                printf("Nekorrektnyi vvod\n");
                printf("Vozvrashenye v menu");
                return 0;
            }
    }
}

void textnextelemadd(struct text* source)
{
    struct text* res;
    char point[1000];
    if(!textvoidcheck(source))
    {
        res=(struct text*)malloc(sizeof(struct text));
        if(source->next!=NULL)
        {
            res->next=source->next;
            res->prev=source;
            source=res->next;
            source->prev=res;
            source=res->prev;
            source->next=res;
        }
        else
        {
            res->prev=source;
            res->next=NULL;
            source->next=res;
        }
        printf("perehod k spisku slov\n");
        res->fild=initsentence();
        res->fild=movetosentence(res->fild);
        showtext(source);
        showtextreversed(source);
    }
    else
    {
        printf("Vy nahodites v pustom spiske\n");
        printf("Nachat zapolnenye spiska?\n");
        printf("Da-1                Net-2\n");
        scanf("%s",point);
        if(atoi(point)==1)
        {
            printf("perehod k spisku slov\n");
            source->fild=initsentence();
            source->fild=movetosentence(source->fild);
            showtext(source);
            showtextreversed(source);
            return 0;
        }
        else
            if(atoi(point)==2)
            {
                printf("Vozvrashenye v menu\n");
                return 0;
            }
            else
            {
                printf("Nekorrektnyi vvod\n");
                printf("Vozvrashenye v menu");
                return 0;
            }
    }
}

struct text* movetotext(struct text* c)
{
    struct sentence* b;
    char point[100000];
    bool flag=false;
    point[0]='\0';
    printf("Vypolnen perehod k spisku predlozhenyi\n");
    while(atoi(point)!=21)
    {
        printf("\n");
        printf("!1.Nachat rabotu s textom-1\n");
        printf("!2.Ochistka spiska-2!\n");
        printf("!3.Proverka spiska napustotu-3!\n");
        printf("!4.Ustanovka ukazatelya v nachalo spiska-4!\n");
        printf("!5.Ustanovka ukazatelya v konec spiska-5!\n");
        printf("!6.Proverka dostigenia nachala spiska-6!\n");
        printf("!7.Proverka dostigenia konca spiska-7!\n");
        printf("!8.Peredvizhenie ukazatelya vpered-8!\n");
        printf("!9.Peredvizhenie ukazatelya nazad-9!\n");
        printf("!10.Vyvod predydushego elementa-10!\n");
        printf("!11.Vyvod sleduyushego elementa-11!\n");
        printf("!12.Udalenye predydushego elementa-12!\n");
        printf("!13.Udalenye sleduyushego elementa-13!\n");
        printf("!14.Vzyatie znachenya predydushego elementa-14!\n");
        printf("!15.Vzyatie znachenya sleduyushego elementa-15!\n");
        printf("!16.Izmenenye znachenya predydushego elementa-16!\n");
        printf("!17.Izmenenye znachenya sleduyushego elementa-17!\n");
        printf("!18.Dobavlenye elementa pered ukazatelem-18!\n");
        printf("!19.Dobavlenye elementa posle ukazatelya-19!\n");
        printf("!20.Vyvod spiska na ekran-20!\n");
        printf("!21.Zaverhit rabotu-21!\n");
        printf("!22.Avaryinoe zavershenye raboty-22!\n");
        printf("Vvedite chislo\n");
        scanf("%s",point);
        if((atoi(point))&&(atoi(point)<=22)&&(atoi(point)>=1))
        {
            if((atoi(point)==1))
            {
                if(flag!=true)
                {
                    flag=true;
                    printf("Spisok predlozhenyi initializirovan\n");
                }
                else
                    printf("spisok uzhe byl initializirovan\n");
            }
            if((atoi(point)==2)&&(flag))
                c=cleantext(c);
            if((atoi(point)==3)&&(flag))
                if(textvoidcheck(c))
                    printf("spisok pust\n");
                else
                    printf("spisok ne pust\n");
            if((atoi(point)==4)&&(flag))
            {
                c=textmovetoroot(c);
                showtext(c);
                showtextreversed(c);
            }
            if((atoi(point)==5)&&(flag))
            {
                c=textmovetoend(c);
                showtext(c);
                showtextreversed(c);
            }
            if((atoi(point)==6)&&(flag))
                if(textrootcheck(c))
                    printf("nachalo dostignuto\n");
                else
                    printf("nachalo ne dostignuto\n");
            if((atoi(point)==7)&&(flag))
            {
                if(textendcheck(c))
                    printf("konec dostignut\n");
                else
                    printf("konec ne dostignut\n");
            }
            if((atoi(point)==8)&&(flag))
            {
                c=textmoveforward(c);
                showtext(c);
                showtextreversed(c);
            }
            if((atoi(point)==9)&&(flag))
            {
                c=textmovebackward(c);
                showtext(c);
                showtextreversed(c);
            }
            if((atoi(point)==10)&&(flag))
            {
                textprevelemshow(c);
                showtext(c);
                showtextreversed(c);
            }
            if((atoi(point)==11)&&(flag))
            {
                textnextelemshow(c);
                showtext(c);
                showtextreversed(c);
            }
            if((atoi(point)==12)&&(flag))
            {
                textprevelemdel(c);
                showtext(c);
                showtextreversed(c);
            }
            if((atoi(point)==13)&&(flag))
            {
                textnextelemdel(c);
                showtext(c);
                showtextreversed(c);
            }
            if((atoi(point)==14)&&(flag))
            {
                b=textprevelemtake(c);
                showsentence(b,b);
            }
            if((atoi(point)==15)&&(flag))
            {
                b=textnextelemtake(c);
                showsentence(b,b);
            }
            if((atoi(point)==16)&&(flag))
               textprevelemchange(c);
            if((atoi(point)==17)&&(flag))
               textnextelemchange(c);    //добавить переход на нижнюю структуру
            if((atoi(point)==18)&&(flag))
                textprevelemadd(c);
            if((atoi(point)==19)&&(flag))
                textnextelemadd(c);
            if((atoi(point)==20)&&(flag))
                showtext(c);
            if((atoi(point)==21)&&(flag))
            {
                flag=true;
                printf("Zavershenye raboty\n");
                return c;
            }
            if((atoi(point)==22)&&(flag))
                exit(0);
            if(flag!=true)
                printf("ERR:Nachnite rabotu so spiskom ili zavershite rabotu\n");
        }
        else
            printf("ERR:Nekorrektnyi vvod\n");
    }
    return 0;
}



bool textbookvoidcheck(struct textbook* root)
{
    if((root->next==NULL)&&(root->fild==NULL))
        return true;
    else
        return false;
}

struct textbook* inittextbook()
{
    struct textbook* res;
    res=(struct textbook*)malloc(sizeof(struct textbook));
    res->next=NULL;
    res->fild=NULL;
    printf("Deck initializirovan\n");
    return res;
}

void showtextbook(struct textbook*root)
{
    struct textbook *res;
    res=root;
    if(res!=NULL)
    {
        if(!textbookvoidcheck(root))
        {
            printf("Vyvod deka\n");
            do
            {
                showtext(res->fild);
                printf("\n");
                printf("\n");
                res=res->next;
            }while(res!=NULL);
        }
        else
            printf("dek pust\n");
    }
}

struct textbook* cleantextbook(struct textbook* root)
{
    struct textbook *res,*tmp;
    if(!textbookvoidcheck(root))
    {
        res=root->next;
        root->fild=NULL;
        root->next=NULL;
        while(res!=NULL)
        {
            tmp=res;
            res=res->next;
            free(tmp);
        }
        root->kount=0;
        printf("Deck ochishen\n");
    }
    else
        printf("Deck uzhe byl ochishen\n");
    return root;
};

void startelemshow(struct textbook *root)
{
    if(!textbookvoidcheck(root))
    {
        printf("\n Pervyi element\n");
        showtext(root->fild);
    }
    else
        printf("Deck pust\n");
}

void endelemshow(struct textbook *root)
{
    struct textbook* res;
    if(!textbookvoidcheck(root))
    {
        res=root;
        while(res->next!=NULL)
            res=res->next;
        printf("\n Poslednyi element\n");
        showtext(res->fild);
    }
    else
        printf("Deck pust\n");

}

struct textbook* movetoend(struct textbook* root)
{
    while(root->next!=NULL)
        root=root->next;
    return root;
}

void endelemdelete(struct textbook* root)
{
    struct textbook *res,*tmp;
    if(root->next!=NULL)
    {
        res=root;
        while(res->next!=movetoend(root))
            res=res->next;
        tmp=movetoend(root);
        free(tmp);
        res->next=NULL;
        root->kount=root->kount-1;
        showtextbook(root);
    }
    else
    {
        if(!textbookvoidcheck(root))
        {
            root=cleantextbook(root);
            return root;
        }
        else
        {
            printf("Dek pust\n");
            return root;
        }
    }
}

struct textbook* startelemdelete(struct textbook*root)
{
    struct textbook *tmp;
    if(root->next!=NULL)
    {
        tmp=root;
        root=root->next;
        free(tmp);
        root->kount=root->kount-1;
        showtextbook(root);
        return root;
    }
    else
    {
        if(!textbookvoidcheck(root))
        {
            root=cleantextbook(root);
            return root;
        }
        else
        {
            printf("Dek pust\n");
            return root;
        }
    }
}

struct text* startelemtake(struct textbook*root)
{
    if(!textbookvoidcheck(root))
        return root->fild;
    else
    {
        printf("Deck pust\n");
        return NULL;
    }
}

struct text* endelemtake(struct textbook* root)
{
    if(!textbookvoidcheck(root))
    {
        root=movetoend(root);
        return root->fild;
    }
    else
    {
        printf("Deck pust\n");
        return NULL;
    }
}

void startelemchange(struct textbook* root)
{
    if(!textbookvoidcheck(root))
    {
        root->fild=movetotext(root->fild);
        showtextbook(root);
    }
    else
        printf("Deck puist\n");
}

void endelemchange(struct textbook* root)
{
    struct textbook* tmp;
    if(!textbookvoidcheck(root))
    {
        tmp=movetoend(root);
        tmp->fild=movetotext(tmp->fild);
        showtextbook(root);
    }
    else
        printf("Deck puist\n");
}

struct textbook* addtostart(struct textbook*root)
{
    struct textbook* res;
    char point[1000];
    if((!textbookvoidcheck(root))&&((root->kount+1)<=root->border))
    {
        res=(struct textbook*)malloc(sizeof(struct textbook));
        res->fild=inittext();
        res->fild=movetotext(res->fild);
        res->next=root;
        root->kount++;
        showtextbook(res);
        return res;
    }
    else
        if((root->kount+1)>root->border)
        {
            printf("Dostignuto maximalnoe kollichestvo elmentov deka\n");
            return root;
        }
        else
        {
        printf("Deck pust\n Hotite nachat ego zapolnenye?\n");
        printf("Da-1                                Net-2\n");
        scanf("%s",point);
        if(atoi(point)==1)
        {
            root->fild=inittext();
            root->fild=movetotext(root->fild);
            root->kount=1;
            showtextbook(root);
            return root;
        }
        else
            if(atoi(point)==2)
            {
                printf("Vozvrashenye v menu\n");
                return root;
            }
            else
                if(atoi(point)==0)
                {
                    printf("Nekorrectnyi vvod\n");
                    printf("Vozvrashenye v menu\n");
                    return root;
                }
    }
}

void addtoend(struct textbook*root)
{
    struct textbook* res,*tmp;
    char point[1000];
    if((!textbookvoidcheck(root))&&((root->kount+1)<=root->border))
    {
        res=(struct textbook*)malloc(sizeof(struct textbook));
        res->fild=inittext();
        res->fild=movetotext(res->fild);
        tmp=movetoend(root);
        tmp->next=res;
        res->next=NULL;
        root->kount++;
        showtextbook(root);
    }
    else
        if((root->kount+1)>root->border)
        {
            printf("Dostignuto maximalnoe kollichestvo elmentov deka\n");
            return root;
        }
        else
        {
        printf("Deck pust\n Hotite nachat ego zapolnenye?\n");
        printf("Da-1                                Net-2\n");
        scanf("%s",point);
        if(atoi(point)==1)
        {
            root->fild=inittext();
            root->fild=movetotext(root->fild);
            root->kount=1;
            showtextbook(root);
        }
        else
            if(atoi(point)==2)
            {
                printf("Vozvrashenye v menu\n");
                return root;
            }
            else
                if(atoi(point)==0)
                {
                    printf("Nekorrectnyi vvod\n");
                    printf("Vozvrashenye v menu\n");
                    return root;
                }
    }
}

struct textbook* endwork(struct textbook* root)
{
    root=cleantextbook(root);
    root=NULL;
    return root;
}


int main()
{
    struct textbook *tb,*root;
    struct text *txt;
    char b,point[100000];
    bool flag=false;
        while(atoi(point)!=16)
        {
            printf("\n");
            printf("!1.Nachalo raboty s dekom-1!\n");
            printf("!2.Ochistka deka-2!\n");
            printf("!3.Proverka deka napustotu-3!\n");
            printf("!4.Vyvod znachenya v nachale deka-4!\n");
            printf("!5.Vyvod znachenya v konce deka-5!\n");
            printf("!6.Udalenye nachala deka-6!\n");
            printf("!7.Udalenye konca deka-7!\n");
            printf("!8.Vzytie elementa iz nachala deka-8!\n");
            printf("!9.Vzytie elementa s konca deka-9!\n");
            printf("!10.Izmenenye znachenya v nachale deka-10!\n");
            printf("!11.Izmenenye znachenya v konce deka-11!\n");
            printf("!12.Dobavlenye elementa v nachalo deka-12!\n");
            printf("!13.Dobavlenye elementa v konec deka-13!\n");
            printf("!14.Vyvod deka na ekran-14!\n");
            printf("!15.Zakonchyt rabotu s dekom-15!\n");
            printf("!16.Vyhod iz programmy-16\n");
            printf("Vvedite chislo\n");
            scanf("%s",point);
            if((atoi(point))&&(atoi(point)<=16)&&(atoi(point)>=1))
            {
                if((atoi(point)==1))
                {
                    if(flag!=true)
                    {
                        flag=true;
                        root=inittextbook();
                        root->border=5;
                        root->kount=0;
                        tb=root;
                    }
                    else
                        printf("Deck uzhe byl initiaslizirovan\n");
                }
                if((atoi(point)==2)&&(flag))
                    root=cleantextbook(root);
                if((atoi(point)==3)&&(flag))
                    if(textbookvoidcheck(root))
                        printf("dek pust\n");
                    else
                        printf("dek ne pust\n");
                if((atoi(point)==4)&&(flag))
                    startelemshow(root);
                if((atoi(point)==5)&&(flag))
                    endelemshow(root);
                if((atoi(point)==6)&&(flag))
                    root=startelemdelete(root);
                if((atoi(point)==7)&&(flag))
                    endelemdelete(root);
                if((atoi(point)==8)&&(flag))
                {
                    txt=startelemtake(root);
                    if(txt!=NULL)
                        showtext(txt);
                }
                if((atoi(point)==9)&&(flag))
                {
                    txt=endelemtake(root);
                    if(txt!=NULL)
                        showtext(txt);
                }
                if((atoi(point)==10)&&(flag))
                    startelemchange(root);
                if((atoi(point)==11)&&(flag))
                    endelemchange(root);
                if((atoi(point)==12)&&(flag))
                    root=addtostart(root);
                if((atoi(point)==13)&&(flag))
                    addtoend(root);
                if((atoi(point)==14)&&(flag))
                    showtextbook(root);
                if((atoi(point)==15)&&(flag))
                {
                    root=endwork(root);
                    flag=false;
                    printf("zavershenye raboty s dekom\n");
                }
                if((atoi(point)==16))
                {
                    printf("Vypolnen vyhod iz programmy\n");
                    exit(0);
                }
                if(flag!=true)
                    printf("Nachnite rabotu s dekom ili zavershite rabotu\n");
            }
            else
                printf("ERR:Nekorrektnyi vvod\n");
}
return 0;
}
