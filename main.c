#include<stdio.h>
#include<stdlib.h>
#include <time.h>    // for clock_gettime()
#include <unistd.h>    // for sleep()
#include <sys/time.h>
#define max 20

int adj[max][max];
int n;
int src, dst, weight;


/**
 * Dijkstra's Algorithm
 * greedy algo, negative weight is not allowed
 * return the shortest distance betweeb src and dst
 */

int dijkstra(int src, int dst, int A[n][n]) {
    
    int visible[n];
    int visited[n];
    int counter = 0;
    int min = -1;

    for (int i=0; i<n; i++) {
        visible[i] = weight;
        visited[i] = 0;
    }
    visible[src] = 0;

    int min_distance;
    while (counter < n)
    {
        min_distance = weight;
        // find the unvisited, visible node with min distance
        for (int i=0; i<n; i++) {
            if (visible[i]<min_distance && visited[i]==0) {
                min = i;
                min_distance = visible[i];
            }
        }

        visited[min] = 1;

        // undate visible
        for (int i=0; i<n; i++) {
            if (A[min][i]>0 && ((visible[min]+A[min][i])<visible[i])) {
                visible[i] = visible[min] + A[min][i];
            }
        }
        counter++;
    }
    //printf("%d\n",visible[dst]);
    return visible[dst];


}/*End of Dijkstra()*/

/**
 * Bellman-Ford Algorithm
 * dynamic programming, negative weight is allowed, but negative cycle is not allowed
 * return the shortest distance betweeb src and dst
 */
int BF(int src, int dst, int A[n][n]) {


    int visible[n];
    int updated; // a flag for earlier return

    for (int i=0; i<n; i++) {
        visible[i] = weight; // pass weight
    }
    visible[src] = 0;

    // we need at most SIZE-1 iterations
    for (int k=0; k<n-1; k++) {

        updated = 0;

        // for each visible node if we see a shorter path to it's neighbors, update.
        for (int i=0; i<n; i++) {
            if (visible[i] == weight)
                continue;

            for (int j=0; j<n; j++) {
                if (A[i][j]>0 && (visible[i]+A[i][j])<visible[j]) {
                    visible[j] = visible[i] + A[i][j];
                    updated = 1;
                }
            }
        }

        // if we don't see any improvement, we can exit earlier
        if (updated != 0)
            break;
    }
    //printf("%d\n",visible[dst]);
    return visible[dst];


}/*End of BW()*/


 /**
 * Floyed-Warshall Algorithm
 * dynamic programming, all shortest path, negative weight is allowed, but negative cycle is not allowed
 * return the shortest distance betweeb src and dst
 */
int FW(int src, int dst, int A[n][n]) {


    int result[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) {
                result[i][j] = 0;
            } else if (A[i][j] == 0) {
                result[i][j] = weight;
            } else {
                result[i][j] = A[i][j];
            }
        }
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (result[i][k]==weight || result[k][j]==weight)
                    continue;

                if(result[i][k] + result[k][j] < result[i][j]) {
                    result[i][j] = result[i][k] + result[k][j];
                }
            }
        }
    }
    //printf("%d\n",result[src][dst]);
    return result[src][dst];



}/*End of FW()*/

void create_graph()
{
    int i,max_edges,origin,destin;

    printf("Enter number of nodes : ");
    scanf("%d",&n);
    max_edges=n*(n-1); /* Taking directed graph */

    for(i=1;i<=max_edges;i++)
    {
        printf("Enter edge %d( 0 0 0 ) to quit : ",i);
        scanf("%d %d %d",&origin,&destin,&weight);
        if((origin==0) && (destin==0))
            break;
        if( origin > n || destin > n || origin<=0 || destin<=0)
        {
            printf("Invalid edge!\n");
            i--;
        }
        else
            adj[origin][destin]=weight;
    }/*End of for*/
}/*End of create_graph()*/

void display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%4d",adj[i][j]);
        printf("\n");
    }
}/*End of display()*/

void insert_node()
{
    int i;
    n++;    /*Increase number of nodes in the graph*/
    printf("The inserted node is %d \n",n);
    for(i=1;i<=n;i++)
    {
        adj[i][n]=0;
        adj[n][i]=0;
    }
}/*End of insert_node()*/

void delete_node(char u)
{
    int i,j;
    if(n==0)
    {
        printf("Graph is empty\n");
        return;
    }
    if( u>n )
    {
        printf("This node is not present in the graph\n");
        return;
    }
    for(i=u;i<=n-1;i++)
       for(j=1;j<=n;j++)
       {
        adj[j][i]=adj[j][i+1];  /* Shift columns left */
        adj[i][j]=adj[i+1][j];  /* Shift rows up */
       }
    n--; /*Decrease the number of nodes in the graph */
}/*End of delete_node*/

void insert_edge(char u,char v,char w)
{
    if(u > n)
    {
        printf("Source node does not exist\n");
        return;
    }
    if(v > n)
    {
        printf("Destination node does not exist\n");
        return;
    }
    adj[u][v]=w;
}/*End of insert_edge()*/

void del_edge(char u,char v)
{
     if(u>n || v>n || adj[u][v]==0)
     {
    printf("This edge does not exist\n");
    return;
     }
     adj[u][v]=0;
}/*End of del_edge()*/

void user_input()
{
    int src,dst;
    printf("\nEnter the source: ");
    scanf("%d",&src);
    printf("\nEnter the destination: ");
    scanf("%d",&dst);
    printf("\n");

}/*End of user_input()*/


void calc_time()
{
    user_input();
    struct timespec start, end;


    for(int i=1;i<4;i++)
    {
        //start timer
        clock_gettime(CLOCK_MONOTONIC, &start);

        switch(i)
        {
        case 1:
            //FW(src,dst,adj);
            printf("%d\n",FW(src,dst,adj));
             break;
        case 2:
             //dijkstra(src,dst,adj);
             printf("%d\n",dijkstra(src,dst,adj));
             break;
        case 3:
             //BF(src,dst,adj);
             printf("%d\n",BF(src,dst,adj));
             break;
        default:
            printf("code error");

        }
        clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculating total time taken by the program.
       int time_taken;
       //time_taken = (end.tv_sec - start.tv_sec);// * 1e9;
       //time_taken = (time_taken + (end.tv_nsec - start.tv_nsec));
       time_taken= (end.tv_nsec - start.tv_nsec);

       printf("cpu: %d NanoSeconds\n",time_taken );
    }

}/*End of calc_time()*/


int main()
{
    int choice;
    int node,origin,destin,weight;

    create_graph();
    while(1)
    {
        printf("1.Insert a node\n");
        printf("2.Insert an edge\n");
        printf("3.Delete a node\n");
        printf("4.Delete an edge\n");
        printf("5.Display\n");
        printf("6.Display the CPU runtime : \n");
        printf("7.Exit \n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        printf("\n\n");

                switch(choice)
                {
                 case 1:
                    insert_node();
                    break;
                 case 2:
                    printf("Enter an edge to be inserted : ");
                    fflush(stdin);
                    scanf("%d %d %d",&origin,&destin,&weight);
                    insert_edge(origin,destin,weight);
                    break;
                 case 3:
                    printf("Enter a node to be deleted : ");
                    fflush(stdin);
                    scanf("%d",&node);
                    delete_node(node);
                    break;
                 case 4:
                    printf("Enter an edge to be deleted : ");
                    fflush(stdin);
                    scanf("%d %d",&origin,&destin);
                    del_edge(origin,destin);
                    break;
                 case 5:
                    display();
                    break;
                 case 6:
                        printf("Display the CPU runtime :");
                        calc_time();
                    break;
                case 7:
                        exit(0);
                        break;
                 default:
                    printf("Wrong choice\n");
                    break;
                 }/*End of switch*/
            }/*End of while*/
    return 0;
}





