// Tell the difference between code1 and code2.

// code1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tagNode
{
    long long x, y;
}Node;


double calculateTriangleArea(Node point1, Node point2, Node point3)
{
    long long temp1 = point1.x * point2.y + point2.x * point3.y + point3.x * point1.y;
    long long temp2 = point1.y * point2.x + point2.y * point3.x + point3.y * point1.x;
    return (double) (temp1 - temp2) / 2;
}

int main()
{
    int num_main = 0;
    scanf("%d", &num_main);
    
    Node* point_main = (Node*)malloc(num_main * sizeof(Node));
    if (point_main == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < num_main; i++)
    {
        scanf("%lld %lld", &point_main[i].x, &point_main[i].y);
    }
    
    double total_area_main = 0;
    for (int i = 1; i < num_main - 1; i++)
    {
        total_area_main += calculateTriangleArea(point_main[0], point_main[i], point_main[i + 1]);
    }
    
    total_area_main = round(total_area_main * 10) / 10;
    printf("%.1lf", fabs(total_area_main));

    free(point_main);
    return 0;
}

// code2
/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct point
{
   double x,y;
}point;

//struct point samepoint;

int main(int argc, char const *argv[])
{
    double area=0,calculate;
    int n,i;
    scanf("%d",&n);
    point p[n];
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf",&p[i].x,&p[i].y);
    }

    for(i=1;i<n-1;i++)
    { 
        calculate = (((p[0].x*p[i].y + p[i].x*p[i+1].y + p[i+1].x*p[0].y)-(p[i].x*p[0].y + p[i+1].x*p[i].y + p[0].x*p[i+1].y)))/2;
        area = area + calculate;
    }
    printf("%.1lf\n",fabs(area));
}*/