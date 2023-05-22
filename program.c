#include<stdio.h>
#include<string.h>
struct product
    {
        char name[10];
        int quantity;
        int price;
        int ptotal;
        int gift;
    }p[3];
void main()
{
    int i,subtotal=0,discount=0,total_quantity=0,diff,discount_category,gift_wrap_cost=0,shipping_fee=0,total=0;
    float discount_temporary;
    char discount_name[4][20]={"flat_10_discount","bulk_5_discount","bulk_10_discount","tiered_50_discount"};
    strcpy(p[0].name,"Product A");
    strcpy(p[1].name,"Product B");
    strcpy(p[2].name,"Product C");
    p[0].price=20;
    p[1].price=40;
    p[2].price=50;
    for(i=0;i<3;i++)
    {
        printf ("Enter the quantity of %s (price = %d$) : ",p[i].name,p[i].price);
        scanf("%d",&p[i].quantity);
        if(p[i].quantity>0)
            {   
                printf("Should %s be wrapped as gift, enter 0 for no and 1 for yes : ",p[i].name);
                scanf("%d",&p[i].gift);
            }
    }
    printf("\nProduct name\tQuantity\tTotal\n");
    for(i=0;i<3;i++)
    {
        if(p[i].quantity>0)
        {
            p[i].ptotal=p[i].price*p[i].quantity;
            subtotal+=p[i].ptotal;
            total_quantity+=p[i].quantity;
            printf("\n%s\t%d\t\t%d$\n",p[i].name,p[i].quantity,p[i].ptotal);
        }
    }
    printf("\n\nSubtotal \t : %d$\n",subtotal);
    if(subtotal>200)
    {
        discount=10;
        discount_category=0;
    }
    for(i=0;i<3;i++)
    {
        if (p[i].quantity>10)
        {
            discount_temporary=p[i].ptotal/20;
            if(discount_temporary>discount)
            {
                discount=discount_temporary;
                discount_category=1;
            }
        }
    }
    if (total_quantity>20)
    {
        discount_temporary=subtotal/10;
        if (discount_temporary>discount)
        {
                discount=discount_temporary;
                discount_category=2;
        }
            
    }
    if (total_quantity>30)
    {
        for(i=0;i<3;i++)
        {
            if (p[i].quantity>15)
            {
                diff=p[i].quantity-15;
                discount_temporary=p[i].price*(diff/2);
            }
            
        }
        if(discount_temporary>discount)
        {
            discount=discount_temporary;
            discount_category=3;
        }
        
    }
    if(discount!=0)
    {
    printf("\nDiscount applied : %s\n",discount_name[discount_category]);
    }   
    printf("\nDiscount amount  : %d$\n",discount);
    for(i=0;i<3;i++)
    {
        if(p[i].gift)
        {
            gift_wrap_cost+=p[i].quantity;
        }
    }
    printf("\nGift wrap fee \t : %d$\n",gift_wrap_cost);
    if(total_quantity>0)
    {
        shipping_fee=(total_quantity/10)*5;
        if(total_quantity%10!=0)
        {
            shipping_fee+=5;
        }
    }
    printf("\nShipping fee \t : %d$\n",shipping_fee);
    total=subtotal-discount+gift_wrap_cost+shipping_fee;
    printf("\nTotal \t\t : %d$\n\n",total);
    
}