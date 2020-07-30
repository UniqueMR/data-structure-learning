#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODESIZE 100
#define TEXTSIZE 1000

//全局变量
//n用以存储基础字符的数量
int n = 0;

//定义哈夫曼树结点和哈夫曼树指针
//顺序存储结构存储哈夫曼树的结点
typedef struct
{
    char ch;
    int weight;
    int parent,lchild,rchild;
    int location;
    char *HFCode;
}HTNode,*HuffmanTree;

//定义队列数据类型
//利用队列找到权值最小的两个结点，并构建哈夫曼树
typedef struct
{
    HuffmanTree HF;
    int i;
    int j;
    int size;
}Queue;

//队列初始化操作
Queue InitQueue(Queue q)
{
    q.HF = (HuffmanTree)malloc((n+1)*sizeof(HTNode));
    q.i = 1;
    q.j = 1;
    q.size = 0;

    return q;
}

//入队操作
Queue EnQueue(Queue q,HTNode d)
{
    q.i--;
    q.HF[q.i] = d;
    q.size++;

    return q;
}

//出队操作
HTNode DeQueue(Queue *q)
{
   int temp;

   temp = q->i;
   q->i++;
   q->size--;

   return q->HF[temp];
}

//定义堆栈数据类型
//利用堆栈，依据哈夫曼树对字符进行哈夫曼编码
typedef struct
{
    char HFCode[CODESIZE];
    int rear;
    int size;
}Stack;

//初始化堆栈
void InitStack(Stack *s)
{
    s->rear = 0;
    s->size = 0;
}

//压栈
void Push(Stack *s,char c)
{
    s->HFCode[s->rear] = c;
    s->rear++;
    s->size++;
}

//出栈
void Pop(Stack *s,char *c)
{
    s->rear--;
    s->size--;

    *c = s->HFCode[s->rear];
}
//插入排序操作
Queue Rank(Queue q)
{
    int k;

    for(k = q.i + 1;k <= q.j;k++)
    {
        q.HF[0] = q.HF[k];

        int high;
        int low;
        int mid;

        low = 1;
        high = k - 1;

        while(low <= high)
        {
            mid = (low + high) / 2;

            if(q.HF[0].weight <= q.HF[mid].weight)
            {
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }

        int m;

        for(m = k - 1;m >= high + 1;m--)
        {
            q.HF[m + 1] = q.HF[m];
        }

        q.HF[high + 1] = q.HF[0];
    }

    return q;
}

//哈夫曼编码
//传入哈夫曼树指针，所有的基础字符，对应的所有权值
HuffmanTree HuffmanCoding(HuffmanTree HT,char *ch,int *w)
{
    //m代表哈夫曼树的总结点树
    int m;

    //总结点树等于叶子结点树的两倍 - 1
    m = 2*n - 1;

    //用顺序存储结构存储哈夫曼树
    HT = (HuffmanTree)malloc((m + 1)*sizeof(HTNode));

    int i;

    //1~n号单元存储叶子结点
    for(i = 1;i <= n;i++)
    {
        HT[i].ch = ch[i - 1];
        HT[i].weight = w[i - 1];
        HT[i].parent = HT[i].lchild = HT[i].rchild = 0;
        HT[i].location = i;
    }

    //n + 1 ~ m号单元存储非叶子结点
    for(i = n + 1;i <= m;i++)
    {
        HT[i].ch = '0';
        HT[i].weight = 0;
        HT[i].parent = HT[i].lchild = HT[i].rchild = 0;
        HT[i].location = i;
    }

    for(i = 1;i <= m;i++)
    {
        printf("%d\t%d\n",HT[i].weight,HT[i].location);
    }

    //利用队列实现每次选择权值最小的两个结点
    Queue q;

    q = InitQueue(q);

    //哈夫曼树的前n个结点入队
    for(i = 1;i <= n;i++)
    {
        q.HF[i] = HT[i];
        q.j++;
        q.size++;
    }

    int Parent;

    Parent = n + 1;

    //当队列的长度不为0的时候，构建哈夫曼树
    while(q.size != 1)
    {
        //对q排序，使得权值最小的两个结点在队列的最前面
        q = Rank(q);

        HTNode Lchild;
        HTNode Rchild;

        //权值最小的两个结点分别作为左右孩子
        Lchild = DeQueue(&q);
        Rchild = DeQueue(&q);

            printf("......\n");

        printf("%d\t",Lchild.weight);
        printf("%d\n",Rchild.weight);

        //子结点的父索引分别指向父结点的位置
        HT[Lchild.location].parent = Parent;
        HT[Rchild.location].parent = Parent;

        //父结点的左右孩子索引分别指向左右孩子的位置
        HT[Parent].lchild = Lchild.location;
        HT[Parent].rchild = Rchild.location;

        printf("%d\t",Lchild.location);
        printf("%d\n",Rchild.location);
        printf("%d",Parent);

        //父结点的权值为左右孩子结点权值的和
        HT[Parent].weight = Lchild.weight + Rchild.weight;

        //父结点入队，参与下一轮比较
        q = EnQueue(q,HT[Parent]);

        //父索引 + 1
        Parent++;
    }

    printf("\n");

    for(i = 1;i <= m;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",HT[i].weight,HT[i].location,HT[i].parent,HT[i].lchild,HT[i].rchild);
    }

    Stack *s;

    s = (Stack*)malloc(sizeof(Stack));

    int j;

    char *c;

    c = (char*)malloc(sizeof(char));

    //利用哈夫曼树对结点进行编码
    for(i = 1;i <= n;i++)
    {
        HT[i].HFCode = (char*)malloc(CODESIZE*sizeof(char));

        HTNode p;

        p = HT[i];
//        printf("%c",HT[i].ch);

        InitStack(s);

        while(p.parent != 0)
        {
            //如果p的父结点的左索引指向p，说明p为其父结点的左孩子，哈夫曼码添加一个0
            if(HT[p.parent].lchild == p.location)
            {
                Push(s,'0');
                printf("0");
            }
            else
            {
                Push(s,'1');
                printf("1");
            }
            //更新结点p
            p = HT[p.parent];
        }

        printf("\n");

        j = 0;

        int length = 0;

        while(s->size != 0)
        {
            Pop(s,c);
            HT[i].HFCode[j] = *c;
            j++;
            length++;
        }

        HT[i].HFCode[length] = '\0';
        printf("%s\n",HT[i].HFCode);
    }

    return HT;
}

//初始化哈夫曼树
HuffmanTree Init(HuffmanTree HT)
{
    //文件类型指针
    //用以实现对hfmTree.txt的写入
    FILE *fp;

    fp = fopen("D://数据结构//实验 5.2//hfmTee.txt","w");

    //录入基础字符数目
    printf("Enter the basic number of characters:");
    scanf("%d",&n);

    //ch用以存储基础字符
    char *ch;

    ch = (char*)malloc((n + 1)*sizeof(char));

    //w用以存储所有基础字符的权值
    int *w;

    w = (int*)malloc(n*sizeof(int));

    int i;

    printf("Enter all the basic characters:\n");
    scanf("%s",ch);

    printf("Enter the weight of each characters:\n");

    for(i = 0;i < n;i++)
    {
        scanf("%d",&w[i]);
    }

    HT = HuffmanCoding(HT,ch,w);

    //将基础字符总数写入文件
    fprintf(fp,"%d",n);

    //将所有基础字符写入文件
    fputs(ch,fp);

    //将所有权值写入文件
    for(i = 0;i < n;i++)
        fprintf(fp,"%5d",w[i]);

    for(i = 1;i <= n;i++)
    {
        printf("%c",HT[i].ch);
    }

    for(i=1;i<=n;++i)

		fprintf(fp,"\n%c:%s",HT[i].ch,HT[i].HFCode);

    fclose(fp);

    printf("Initialized successfully!\n");

    return HT;
}

//对文件ToBeTran.txt中的内容进行编码
void Encoding(HuffmanTree HT)
{
    //文件类型的指针
    FILE *fpr,*fpw;

    fpr = fopen("D://数据结构//实验 5.2//hfmTee.txt","r");

    if(feof(fpr))
    {
        printf("HuffmanTree has not be created yet!\n");
        HT = Init(HT);
    }

    fclose(fpr);

    fpr = fopen("D://数据结构//实验 5.2//ToBeTran.txt","r");

    fpw = fopen("D://数据结构//实验 5.2//CodeFile.txt","w");

    char in;
    int i;

    fscanf(fpr,"%c",&in);

    while(!feof(fpr))
    {
        for(i = 1;i <= n;++i)
        {
            if(HT[i].ch == in)
                break;
        }
        fprintf(fpw,"%s",HT[i].HFCode);
        fprintf(fpw," ");
        fscanf(fpr,"%c",&in);
    }

    fclose(fpr);
    fclose(fpw);
}

//对文件CodeFile中的文件进行译码
void Decoding(HuffmanTree HT)
{
    FILE *fpr,*fpw;

    fpr = fopen("D://数据结构//实验 5.2//hfmTee.txt","r");

    if(feof(fpr))
    {
        printf("HuffmanTree has not be created yet!\n");
        HT = Init(HT);
    }

    fclose(fpr);

    fpr = fopen("D://数据结构//实验 5.2//CodeFile.txt","r");
    fpw = fopen("D://数据结构//实验 5.2//TextFile.txt","w");

    char code[CODESIZE];

    fscanf(fpr,"%s",code);

    while(!feof(fpr))
    {
        int i;

        for(i = 1;i <= n;i++)
        {
            if(strcmp(HT[i].HFCode,code) == 0)
                break;
        }

        fprintf(fpw,"%c",HT[i].ch);
        fscanf(fpr,"%s",code);
    }

    fclose(fpr);
    fclose(fpw);
}

//将文件编码显示于终端，并写入文件CodePrin
void Print(HuffmanTree HT)
{
    FILE *fpr,*fpw;

    fpr = fopen("D://数据结构//实验 5.2//CodeFile.txt","r");
    fpw = fopen("D://数据结构//实验 5.2//CodePrin.txt","w");

    char in;

    fscanf(fpr,"%c",&in);
    printf("%c",in);

    //统计单行的字符数
    int count;

    while(!feof(fpr))
    {
        if(in == ' ')
            continue;

        else
        {
            printf("%c",in);
            fprintf(fpw,"%c",in);
            count++;

            //如果每行的字符数超过50，就换行
            if(count == 50)
            {
                printf("\n");
                fprintf(fpw,"\n");
                count = 0;
            }
        }
        fscanf(fpr,"%c",&in);
    }

    fclose(fpr);
    fclose(fpw);
}

//将内存中的哈夫曼树以表格的形式打印在终端上，并写入文件TreePrint中
void TreePrinting(HuffmanTree HT)
{
    FILE *fp;

    fp = fopen("D://数据结构//实验 5.2//TreePrint.txt","w");

    int i;

    for(i = 1;i <= n;i++)
    {
        printf("%c%8d%8d%8d%8d\n",HT[i].ch,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
        fprintf(fp,"%c%8d%8d%8d%8d\n",HT[i].ch,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
        fprintf(fp,"\n");
    }

    fclose(fp);
}

//显示于用户界面的提示信息
void Welcome()
{
    printf("*        请选择如下操作        *\n");
    printf("*          I.初始化            *\n");
    printf("*          E.编码              *\n");
    printf("*          D.译码              *\n");
    printf("*          P.打印代码文件      *\n");
    printf("*          T.打印哈夫曼树      *\n");
    printf("*          Q.退出              *\n");
}

int main()
{
    char choice;
    HuffmanTree HT;

    HT = (HuffmanTree)malloc(sizeof(HTNode));

    while(1)
    {
        Welcome();
        choice = getchar();

        switch(choice)
        {
            case 'i':
            case 'I':HT = Init(HT);    break;
            case 'e':
            case 'E':Encoding(HT);    break;
            case 'd':
            case 'D':Decoding(HT);    break;
            case 'p':
            case 'P':Print(HT);    break;
            case 't':
            case 'T':TreePrinting(HT);    break;
            case 'q':
            case 'Q':free(HT);    exit(1);
            default:printf("Errors in input!\n");
        }
    }

    return 0;
}
