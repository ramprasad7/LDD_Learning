#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Company{
    char name[100];
    char domain[100];
    int noOfEmployees;
    float averageSalary;
}Company;

void dispCompanyDetailsinDomain(Company *c,char *domain,int n){
        for(int i=0;i<n;i++){
            if(!strcmp(c[i].domain,domain)){
                printf("%s\n",c[i].name);
            }
    
        }
}

void dispNoofEmployees(Company *c, char *name,int n){
        for(int i=0;i<n;i++){
            if(!strcmp(c[i].name,name)){
                printf("%d\n",c[i].noOfEmployees);
            }
        }
}

void dispCompanyOfferingHighestAvgSal(Company *c, int n){
    int in;
    float h;
        for(int i=0; i<n; i++){
                h = c[0].averageSalary;
                if(c[i].averageSalary > h) {
                        h =c[i].averageSalary;
                        in=i;
                        break;
                }
        }

        printf("Name : %s\n",c[in].name);
        printf("Domain : %s\n",c[in].domain);
        printf("Name of Employees : %d\n",c[in].noOfEmployees);
        printf("Average Salary : %f\n",c[in].averageSalary);
}

void dispCompanyOfferingHighestAvgSalinDomain(Company *c, char *domain, int n){
        int in;
        float h;
        
        for(int i=0; i<n; i++){
                h = c[0].averageSalary;
                if(!strcmp(domain,c[i].domain)){    
                        if(c[i].averageSalary > h){
                            h = c[i].averageSalary;
                            in = i;
                            break;
                        }
                }
        }
        printf("Name : %s\n", c[in].name);
        printf("Domain : %s\n", c[in].domain);
        printf("Number of Employees : %d\n",c[in].noOfEmployees);
        printf("Average Salary : %f\n",c[in].averageSalary);
}



void dispParticularCompanyDetails(Company *c, char *name, int n){
     int in;

    for(int i=0; i<n; i++){
            if(!strcmp(c[i].name,name)){
                in = i;
                break;
            }
    }


    printf("Name : %s\n", c[in].name);
    printf("Domain : %s\n", c[in].domain);
    printf("Number of Employees : %d\n",c[in].noOfEmployees);
    printf("Average Salary : %f\n",c[in].averageSalary);
}

void dispCompanyDetails(Company *c,int n){
    for(int i=0; i<n; i++){
        printf("Name : %s\n",c[i].name);
        printf("Domain : %s\n",c[i].domain);
        printf("Number of Employees : %d\n",c[i].noOfEmployees);
        printf("Average Salary : %f\n",c[i].averageSalary);
    }
}

void updateSalary(Company *c, float newsalary,char* name,int n){
    int i,in;
    for(i=0;i,n;i++){
        if(!strcmp(c[i].name,name)){
            c[i].averageSalary = newsalary;
            in = i;
            break;
        }
    }
    printf("Company Details after Updated salary\n");
    printf("Name : %s\n",c[in].name);
    printf("Domain : %s\n",c[in].domain);
    printf("Number of Employees : %d\n",c[in].noOfEmployees);
    printf("Average Salary : %f\n",c[in].averageSalary);
}

int main(int argc,char *agrv[]){
    int n,ch,i;
    printf("Enter number of companies\n");
    scanf("%d",&n);

    Company *c;
    c = (Company *)malloc(sizeof(Company)*n + 2);

    printf("Enter the details of the company\n");
    for(i=0;i<n;i++){
        printf("Name\n");
        scanf("%s",c[i].name);
        printf("Enter domain\n");
        scanf("%s",c[i].domain);
        printf("Enter number of employees\n");
        scanf("%d",&c[i].noOfEmployees);
        printf("Enter average salary\n");
        scanf("%f",&c[i].averageSalary);
    }
    while(1){
        printf("Menu\n");
        printf("1.Display names of companies working in a particular domain\n");
        printf("2.Display number of Employees in a particular company\n");
        printf("3.Display all details of the company offering highest average salary \n");
        printf("4.Display all details of the company from particular domain offering the highest average salary\n");
        printf("5.Display all details of a particular company(Search by name)\n");
        printf("6.Display all details of all Companies\n");
        printf("7. Update the average salary of a company\n");
        printf("8.Exit\n");

        printf("Enter choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the domain\n");
                char d[100];
                scanf("%s",d);
                dispCompanyDetailsinDomain(c, d, n);
                break;
                
            }
            case 2:{
                printf("Enter a Company name for a no. of employees\n");
                char nam[100];
                scanf("%s",nam);
                dispNoofEmployees(c, nam, n);
                break;
                
            }
            case 3:{
                dispCompanyOfferingHighestAvgSal(c, n);
                break;
            }
            case 4:{
                printf("Enter the domain\n");
                char d1[100];
                scanf("%s",d1);
                dispCompanyOfferingHighestAvgSalinDomain(c, d1, n);
                break;
            }
            case 5:{
                printf("Enter a company name\n");
                char nam1[100];
                scanf("%s",nam1);
                dispParticularCompanyDetails(c, nam1, n);
                break;
            }
            case 6:{
                dispCompanyDetails(c,n);
                break;
            }
            case 7:{
                char name1[100];
                printf("Enter company name\n");
                scanf("%s",name1);
                printf("Enter the update salary\n");
                float sal;
                scanf("%f",&sal);
                updateSalary(c,sal,name1,n);
                break;               
            }
            case 8:{
                exit(1);
                break;
            }

            default:{
                printf("Invalid Choice\n");
                break;
            }
        }
    }
    free(c);
    return 0;   
}