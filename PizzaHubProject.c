// Please use this line to run the code:
// gcc PizzaHubProject.c -o a.out -lncurses

#include <stdio.h>
#include <string.h>

#define INFINITY 9999
#define MAX 5

void items();
void dijkstra();

int G[MAX][MAX] = {{0, 10, 0, 15, 100},
                   {25, 0, 50, 0, 0},
                   {0, 55, 0, 20, 60},
                   {30, 0, 80, 0, 70},
                   {110, 0, 40, 65, 0}};

struct order
{
    char name[50];
    int order_number;
    int number_of_food;
    int cost;
} p[10000];

int order_count = 0, served_count = 0, waiting_now = 0;

int order()
{
    int n, in, qu;
    printf("\nPlease enter your firstname: ");
    gets(p[order_count].name);
    p[order_count].order_number = order_count;
    items();
    p[order_count].number_of_food = n;
    p[order_count].cost = 0;
    p[order_count].number_of_food = 0;
level:
    printf("How many items you want to order? ");
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        printf("\nEnter chosen item code\n");
        scanf("%d", &in);
        getchar();
        switch (in)
        {
        case 1:
        {
            printf("Enter the size of Peppy Paneer Pizza: 1. 12inch  2. 14inch 3. 16inch\n");
            int i;
            scanf("%d", &i);
            getchar();
            printf("Please enter the quantity: ");
            scanf("%d", &qu);
            getchar();
            p[order_count].number_of_food += qu;
            if (i == 1)
                p[order_count].cost += (215 * qu);
            else if (i == 2)
                p[order_count].cost += (395 * qu);
            else
                p[order_count].cost += (595 * qu);
            break;
        }
        case 2:
        {
            printf("Enter the size of Margherita Pizza: 1. 12inch  2. 14inch  3. 16inch\n");
            int i;
            scanf("%d", &i);
            getchar();
            printf("Please enter the quantity: ");
            scanf("%d", &qu);
            getchar();
            p[order_count].number_of_food += qu;
            if (i == 1)
                p[order_count].cost += (235 * qu);
            else if (i == 2)
                p[order_count].cost += (400 * qu);
            else
                p[order_count].cost += (695 * qu);
            break;
        }
        case 3:
        {
            printf("Enter the size of Veggie Paradise Pizza: 1. 12inch  2. 14inch  3. 16inch\n");
            int i;
            scanf("%d", &i);
            getchar();
            printf("Please enter the quantity: ");
            scanf("%d", &qu);
            getchar();
            p[order_count].number_of_food += qu;
            if (i == 1)
                p[order_count].cost += (315 * qu);
            else if (i == 2)
                p[order_count].cost += (495 * qu);
            else
                p[order_count].cost += (700 * qu);
            break;
        }
        case 4:
        {
            printf("Enter the size of Farmhouse Pizza: 1. 12inch  2. 14inch  3. 16inch\n");
            int i;
            scanf("%d", &i);
            getchar();
            printf("Please enter the quantity: ");
            scanf("%d", &qu);
            getchar();
            p[order_count].number_of_food += qu;
            if (i == 1)
                p[order_count].cost += (235 * qu);
            else if (i == 2)
                p[order_count].cost += (400 * qu);
            else
                p[order_count].cost += (705 * qu);
            break;
        }
        case 5:
        {
            printf("Enter the size of Arabiata Pasta: 1. half  2. full\n");
            int i;
            scanf("%d", &i);
            getchar();
            printf("Please enter the quantity: ");
            scanf("%d", &qu);
            getchar();
            p[order_count].number_of_food += qu;
            if (i == 1)
                p[order_count].cost += (130 * qu);
            else
                p[order_count].cost += (250 * qu);
            break;
        }
        case 6:
        {
            printf("Enter the size of Pesto Pasta: 1. half  2. full\n");
            int i;
            scanf("%d", &i);
            getchar();
            printf("Please enter the quantity: ");
            scanf("%d", &qu);
            getchar();
            p[order_count].number_of_food += qu;
            if (i == 1)
                p[order_count].cost += (120 * qu);
            else
                p[order_count].cost += (240 * qu);
            break;
        }
        case 7:
        {
            printf("250 mg of OREO SHAKE\n");
            printf("Please enter the quantity: ");
            scanf("%d", &qu);
            getchar();
            p[order_count].number_of_food += qu;
            p[order_count].cost += (180 * qu);
            break;
        }
        case 8:
        {
            printf("250 mg of Cold Coffee\n");
            printf("Please enter the quantity: ");
            scanf("%d", &qu);
            getchar();
            p[order_count].number_of_food += qu;
            p[order_count].cost += (65 * qu);
            break;
        }
        case 9:
        {
            printf("250 mg of Cappuccino\n");
            printf("Please enter the quantity: ");
            scanf("%d", &qu);
            getchar();
            p[order_count].number_of_food += qu;
            p[order_count].cost += (70 * qu);
            break;
        }
        case 10:
        {
            printf("Enter the size of Coke: 1. 250mg  2. 500mg\n");
            int i;
            scanf("%d", &i);
            getchar();
            printf("Please enter the quantity: ");
            scanf("%d", &qu);
            getchar();
            p[order_count].number_of_food += qu;
            if (i == 1)
                p[order_count].cost += (20 * qu);
            else
                p[order_count].cost += (30 * qu);
            break;
        }
        default:
        {
            printf("Invalid selection try again\n");
            n++;
        }
        }
    }
    char temp;
    printf("\nDo you want to order anything else?(y/n)\n ");
    scanf("%c", &temp);
    if (temp == 'y' || temp == 'Y')
        goto level;
    printf("\nNumber of food items ordered: %d\n", p[order_count].number_of_food);
    printf("1:Banashankari 2:Koramangala 3:Rajajinagar 4:Malleshwaram\n");
    printf("\nEnter Your Area no.: ");
    int u, i, j;
    int ant = 5;
    scanf("%d", &u);

    dijkstra(G, ant, u);
    // printf("Enter number of Path which u want to be selected!!!!!!");
    // int a;
    // scanf("%d",&a);
    printf("\nThank you %s for your order. Your bill is %drs.\nPlease wait while we prepare the food.\n\n ", p[order_count].name, p[order_count].cost);
    order_count++;
}
int receive()
{
    if (order_count == 0)
    {
        printf("\nPlease order first\n");
        return NULL;
    }
    else if (served_count == order_count)
    {
        printf("\nAll order served\n");
        return NULL;
    }
    printf("\nOrder no. %d for %s is ready\n", p[served_count].order_number + 1, p[served_count].name);
    printf("Enjoy your meal\n\n");
    served_count++;
}
int display()
{
    printf("\nTotal order taken: %d\n", (order_count));
    printf("Total number of order served %d\n", served_count);
    printf("Number of Currently waiting to be served: %d\n", (order_count - served_count));
    printf("Currently preparing food for order no. %d\n\n", p[served_count].order_number);
}
void items()
{
    printf("..................................MENU....................................\n");
    printf("Item Code#   Description-------------------Size--------------------Price(Rs)\n");
    printf("[1]---------Peppy Paneer Pizza----------12/14/16inch---------------215/395/595\n");
    printf("[2]---------Margherita Pizza------------12/14/16inch---------------235/400/695\n");
    printf("[3]---------Veggie Paradise Pizaa-------12/14/16inch---------------315/495/700\n");
    printf("[4]---------Farmhouse Pizza-------------12/14/16inch---------------235/400/705\n");
    printf("[5]---------Arabiata Pasta--------------Half/Full------------------130/250\n");
    printf("[6]---------Pesto Pasta-----------------Half/Full------------------120/240\n");
    printf("[7]---------Oreo Shake------------------250mg----------------------180\n");
    printf("[8]---------Cold Coffee-----------------250mg----------------------65\n");
    printf("[9]---------Cappuccino------------------250mg----------------------70\n");
    printf("[10]--------Coke------------------------250/500mg------------------20/30\n\n");
}
int main()
{
    char pizza_hut_logo[] =
        "\n\t\t\t\t\t ___                             _   _           _     \n"
        "\t\t\t\t\t(  _`\\  _                       ( ) ( )         ( )    \n"
        "\t\t\t\t\t| |_) )(_) ____  ____    _ _    | |_| |   _   _ | |__  \n"
        "\t\t\t\t\t| ,__/'| |(_  ,)(_  ,) /'_` )   |  _  |  ( ) ( )| /  \\\n"
        "\t\t\t\t\t| |    | | /'/_  /'/_ ( (_| |   | | | |  | (_) || |__||\n"
        "\t\t\t\t\t(_)    (_)(____)(____)` \\__,_)  (_) (_)`  \\___/` \\\\__))\n";
    printf("%s", pizza_hut_logo);
    while (1)
    {
        printf("\n1. Order\n2. Serve\n3. Display \n4. Exit the program\n\n");
        int in;
        scanf("%d", &in);
        getchar();
        switch (in)
        {
        case 1:
        {
            order();
            break;
        }
        case 2:
        {
            receive();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("\nWe are closed come by again\n\n");
            return 0;
        }
        }
    }
}

void dijkstra(int G[MAX][MAX], int n, int startnode) 
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    //pred[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    //create the time matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
    //initialize pred[],distance[] and visited[]
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindistance = INFINITY;
        //nextnode gives the node at minimum distance
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }

        //check if a better path exists through nextnode
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    //print the path and distance of each node
    for (i = 0; i < startnode; i++)
        if (i != startnode)
        {
            printf("\n\nWay %d", i+1);
            printf("\nTime to reach destination=%d mins", distance[i]);
            printf("\nPizza Hub");

            j = i;
            do
            {
                j = pred[j];
                printf("<-%d", j);
            } while (j != startnode);
        }
    int min;
    min = distance[0];
    for (i = 1; i < startnode; i++)
    {

        if (min > distance[i])
        {
            min = distance[i];
        }
    }
    printf("\n\n\nMinimum time is %d mins", min);
}
