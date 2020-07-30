#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODESIZE 100
#define TEXTSIZE 1000

//ȫ�ֱ���
//n���Դ洢�����ַ�������
int n = 0;

//��������������͹�������ָ��
//˳��洢�ṹ�洢���������Ľ��
typedef struct
{
    char ch;
    int weight;
    int parent,lchild,rchild;
    int location;
    char *HFCode;
}HTNode,*HuffmanTree;

//���������������
//���ö����ҵ�Ȩֵ��С��������㣬��������������
typedef struct
{
    HuffmanTree HF;
    int i;
    int j;
    int size;
}Queue;

//���г�ʼ������
Queue InitQueue(Queue q)
{
    q.HF = (HuffmanTree)malloc((n+1)*sizeof(HTNode));
    q.i = 1;
    q.j = 1;
    q.size = 0;

    return q;
}

//��Ӳ���
Queue EnQueue(Queue q,HTNode d)
{
    q.i--;
    q.HF[q.i] = d;
    q.size++;

    return q;
}

//���Ӳ���
HTNode DeQueue(Queue *q)
{
   int temp;

   temp = q->i;
   q->i++;
   q->size--;

   return q->HF[temp];
}

//�����ջ��������
//���ö�ջ�����ݹ����������ַ����й���������
typedef struct
{
    char HFCode[CODESIZE];
    int rear;
    int size;
}Stack;

//��ʼ����ջ
void InitStack(Stack *s)
{
    s->rear = 0;
    s->size = 0;
}

//ѹջ
void Push(Stack *s,char c)
{
    s->HFCode[s->rear] = c;
    s->rear++;
    s->size++;
}

//��ջ
void Pop(Stack *s,char *c)
{
    s->rear--;
    s->size--;

    *c = s->HFCode[s->rear];
}
//�����������
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

//����������
//�����������ָ�룬���еĻ����ַ�����Ӧ������Ȩֵ
HuffmanTree HuffmanCoding(HuffmanTree HT,char *ch,int *w)
{
    //m��������������ܽ����
    int m;

    //�ܽ��������Ҷ�ӽ���������� - 1
    m = 2*n - 1;

    //��˳��洢�ṹ�洢��������
    HT = (HuffmanTree)malloc((m + 1)*sizeof(HTNode));

    int i;

    //1~n�ŵ�Ԫ�洢Ҷ�ӽ��
    for(i = 1;i <= n;i++)
    {
        HT[i].ch = ch[i - 1];
        HT[i].weight = w[i - 1];
        HT[i].parent = HT[i].lchild = HT[i].rchild = 0;
        HT[i].location = i;
    }

    //n + 1 ~ m�ŵ�Ԫ�洢��Ҷ�ӽ��
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

    //���ö���ʵ��ÿ��ѡ��Ȩֵ��С���������
    Queue q;

    q = InitQueue(q);

    //����������ǰn��������
    for(i = 1;i <= n;i++)
    {
        q.HF[i] = HT[i];
        q.j++;
        q.size++;
    }

    int Parent;

    Parent = n + 1;

    //�����еĳ��Ȳ�Ϊ0��ʱ�򣬹�����������
    while(q.size != 1)
    {
        //��q����ʹ��Ȩֵ��С����������ڶ��е���ǰ��
        q = Rank(q);

        HTNode Lchild;
        HTNode Rchild;

        //Ȩֵ��С���������ֱ���Ϊ���Һ���
        Lchild = DeQueue(&q);
        Rchild = DeQueue(&q);

            printf("......\n");

        printf("%d\t",Lchild.weight);
        printf("%d\n",Rchild.weight);

        //�ӽ��ĸ������ֱ�ָ�򸸽���λ��
        HT[Lchild.location].parent = Parent;
        HT[Rchild.location].parent = Parent;

        //���������Һ��������ֱ�ָ�����Һ��ӵ�λ��
        HT[Parent].lchild = Lchild.location;
        HT[Parent].rchild = Rchild.location;

        printf("%d\t",Lchild.location);
        printf("%d\n",Rchild.location);
        printf("%d",Parent);

        //������ȨֵΪ���Һ��ӽ��Ȩֵ�ĺ�
        HT[Parent].weight = Lchild.weight + Rchild.weight;

        //�������ӣ�������һ�ֱȽ�
        q = EnQueue(q,HT[Parent]);

        //������ + 1
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

    //���ù��������Խ����б���
    for(i = 1;i <= n;i++)
    {
        HT[i].HFCode = (char*)malloc(CODESIZE*sizeof(char));

        HTNode p;

        p = HT[i];
//        printf("%c",HT[i].ch);

        InitStack(s);

        while(p.parent != 0)
        {
            //���p�ĸ�����������ָ��p��˵��pΪ�丸�������ӣ������������һ��0
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
            //���½��p
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

//��ʼ����������
HuffmanTree Init(HuffmanTree HT)
{
    //�ļ�����ָ��
    //����ʵ�ֶ�hfmTree.txt��д��
    FILE *fp;

    fp = fopen("D://���ݽṹ//ʵ�� 5.2//hfmTee.txt","w");

    //¼������ַ���Ŀ
    printf("Enter the basic number of characters:");
    scanf("%d",&n);

    //ch���Դ洢�����ַ�
    char *ch;

    ch = (char*)malloc((n + 1)*sizeof(char));

    //w���Դ洢���л����ַ���Ȩֵ
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

    //�������ַ�����д���ļ�
    fprintf(fp,"%d",n);

    //�����л����ַ�д���ļ�
    fputs(ch,fp);

    //������Ȩֵд���ļ�
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

//���ļ�ToBeTran.txt�е����ݽ��б���
void Encoding(HuffmanTree HT)
{
    //�ļ����͵�ָ��
    FILE *fpr,*fpw;

    fpr = fopen("D://���ݽṹ//ʵ�� 5.2//hfmTee.txt","r");

    if(feof(fpr))
    {
        printf("HuffmanTree has not be created yet!\n");
        HT = Init(HT);
    }

    fclose(fpr);

    fpr = fopen("D://���ݽṹ//ʵ�� 5.2//ToBeTran.txt","r");

    fpw = fopen("D://���ݽṹ//ʵ�� 5.2//CodeFile.txt","w");

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

//���ļ�CodeFile�е��ļ���������
void Decoding(HuffmanTree HT)
{
    FILE *fpr,*fpw;

    fpr = fopen("D://���ݽṹ//ʵ�� 5.2//hfmTee.txt","r");

    if(feof(fpr))
    {
        printf("HuffmanTree has not be created yet!\n");
        HT = Init(HT);
    }

    fclose(fpr);

    fpr = fopen("D://���ݽṹ//ʵ�� 5.2//CodeFile.txt","r");
    fpw = fopen("D://���ݽṹ//ʵ�� 5.2//TextFile.txt","w");

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

//���ļ�������ʾ���նˣ���д���ļ�CodePrin
void Print(HuffmanTree HT)
{
    FILE *fpr,*fpw;

    fpr = fopen("D://���ݽṹ//ʵ�� 5.2//CodeFile.txt","r");
    fpw = fopen("D://���ݽṹ//ʵ�� 5.2//CodePrin.txt","w");

    char in;

    fscanf(fpr,"%c",&in);
    printf("%c",in);

    //ͳ�Ƶ��е��ַ���
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

            //���ÿ�е��ַ�������50���ͻ���
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

//���ڴ��еĹ��������Ա�����ʽ��ӡ���ն��ϣ���д���ļ�TreePrint��
void TreePrinting(HuffmanTree HT)
{
    FILE *fp;

    fp = fopen("D://���ݽṹ//ʵ�� 5.2//TreePrint.txt","w");

    int i;

    for(i = 1;i <= n;i++)
    {
        printf("%c%8d%8d%8d%8d\n",HT[i].ch,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
        fprintf(fp,"%c%8d%8d%8d%8d\n",HT[i].ch,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
        fprintf(fp,"\n");
    }

    fclose(fp);
}

//��ʾ���û��������ʾ��Ϣ
void Welcome()
{
    printf("*        ��ѡ�����²���        *\n");
    printf("*          I.��ʼ��            *\n");
    printf("*          E.����              *\n");
    printf("*          D.����              *\n");
    printf("*          P.��ӡ�����ļ�      *\n");
    printf("*          T.��ӡ��������      *\n");
    printf("*          Q.�˳�              *\n");
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
