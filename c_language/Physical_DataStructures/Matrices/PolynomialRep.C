#include<stdio.h>
#include<stdlib.h>

using namespace std;

/* Representing polynomial equation using programatic way
3x²+2x¹+1x⁰

To represent this into list so that we can perform operations on them.

p1:
coefficient 3   2   1
exponent    2   1   0


Adding two polynomials

p2:
coefficient 3   2   5   1
exponent    3   2   1   0


Sum:
coefficient 3   5   7   2
exponent    3   2   1   0

Here if p1.exponent >p2.exponent then copy p1.term into sum
else if p1.exponent<p2.exponent then copy p2.term into sum
else p1.exponent == p2.exponent then sum coefficients of p1+p2 and put into the sum.

*/

struct Term
{
    int coeff;
    int expo;
};

struct Poly
{
    int n;
    struct Term *t;
};

void Create(struct Poly *p)
{
    int i;
    printf("No of terms?");
    scanf("%d",&p->n);
    p->t = (struct Term *) malloc(p->n*sizeof(struct Term));

    printf("Enter the terms ");
    for(i=0;i<p->n;i++)
    {
        scanf("%d%d",&p->t[i].coeff,&p->t[i].expo);
    }
}

void Display(struct Poly p)
{
    int i;
    for(i=0;i<p.n;i++)
    {
        printf("%dX%d+",p.t[i].coeff,p.t[i].expo);
    }
    printf("\n");
}


int main()
{
    struct Poly p;
    Create(&p);
    Display(p);

    return 0;
}