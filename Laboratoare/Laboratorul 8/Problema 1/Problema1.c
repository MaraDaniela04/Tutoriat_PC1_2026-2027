#include <stdio.h>
#include <stdlib.h>
    struct complex{
                float re,im;
                void (*citire)(struct complex *c);
                void (*afisare)(struct complex c);
              };
    void citire(struct complex *c)
    {
        scanf("%f %f",&c->re,&c->im);
    }
    void afisare(struct complex c)
    {   if(c.re!=0)
        printf("%f ",c.re);
        if(c.im!=0)
        {
            if(c.im>0){printf("+ "); printf("%fi",c.im);}
            else {printf("- "); printf("%fi",c.im);}
        }
    }
    struct complex produs(struct complex *a, struct complex *b)
    {struct complex r;
     r.re=a->re*b->re-a->im*b->im;
     r.im=a->im*b->re+a->re*b->im;
     return r;
    }
    struct complex suma(struct complex *a, struct complex *b)
    {struct complex r;
    r.re=a->re+b->re;
    r.im=a->im+b->im;
    return r;
    }
      struct complex operatie(struct complex *a, struct complex *b, struct complex(*f)(struct complex *, struct complex *))
      {
          return f(a,b);
      }
int main()
{
        struct complex X,Y,XX,ec1,X2,ec2;
        X.citire=citire;
        Y.citire=citire;
        X.citire(&X);
        Y.citire(&Y);
        XX=operatie(&X,&X,produs);
        ec1=operatie(&XX,&Y,produs);
        ec1.afisare=afisare;
        ec1.afisare(ec1);
        printf("\n");
        X2=operatie(&X,&X,suma);
        ec2=operatie(&X2,&Y,suma);
        ec2.afisare=afisare;
        ec2.afisare(ec2);

    return 0;
}
