//Fractional knapsack problem, Job Sequencing with deadline,Kruskal's algorithm, prims algorithm, Dijkstra's algorithm.


#include<stdio.h>

#define MAX 50
#define INF 9999

/* ================= FRACTIONAL KNAPSACK ================= */

void fractionalKnapsack(){
    int n, capacity;
    int weight[MAX], profit[MAX], index[MAX];
    float ratio[MAX], totalProfit = 0;

    printf("\nEnter number of items: ");
    scanf("%d",&n);

    printf("Enter weight and profit of each item:\n");
    for(int i=0;i<n;i++){
        scanf("%d%d",&weight[i],&profit[i]);
        ratio[i]=(float)profit[i]/weight[i];
        index[i]=i;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d",&capacity);

    // Sort by ratio descending
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                float tr=ratio[i]; ratio[i]=ratio[j]; ratio[j]=tr;
                int ti=index[i]; index[i]=index[j]; index[j]=ti;
            }
        }
    }

    for(int i=0;i<n;i++){
        int k=index[i];
        if(weight[k]<=capacity){
            capacity-=weight[k];
            totalProfit+=profit[k];
        }
        else{
            totalProfit+=profit[k]*((float)capacity/weight[k]);
            break;
        }
    }

    printf("Maximum Profit = %.2f\n",totalProfit);
}


/* ================= JOB SEQUENCING ================= */

void jobSequencing(){
    int n;
    printf("\nEnter number of jobs: ");
    scanf("%d",&n);

    int profit[MAX], deadline[MAX], slot[MAX]={0};

    printf("Enter profit and deadline:\n");
    for(int i=0;i<n;i++)
        scanf("%d%d",&profit[i],&deadline[i]);

    // Sort by profit descending
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(profit[i]<profit[j]){
                int tp=profit[i]; profit[i]=profit[j]; profit[j]=tp;
                int td=deadline[i]; deadline[i]=deadline[j]; deadline[j]=td;
            }
        }
    }

    int maxDeadline=0;
    for(int i=0;i<n;i++)
        if(deadline[i]>maxDeadline)
            maxDeadline=deadline[i];

    int maxProfit=0;

    for(int i=0;i<n;i++){
        for(int j=deadline[i]-1;j>=0;j--){
            if(slot[j]==0){
                slot[j]=i+1;
                maxProfit+=profit[i];
                break;
            }
        }
    }

    printf("Selected Jobs: ");
    for(int i=0;i<maxDeadline;i++)
        if(slot[i]!=0)
            printf("J%d ",slot[i]);

    printf("\nMaximum Profit = %d\n",maxProfit);
}


/* ================= KRUSKAL ================= */

int find(int parent[],int i){
    while(parent[i])
        i=parent[i];
    return i;
}

void kruskal(){
    int n;
    printf("\nEnter number of vertices: ");
    scanf("%d",&n);

    int cost[MAX][MAX], parent[MAX]={0};

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    int edge=1,mincost=0;

    while(edge<n){
        int min=INF,a=-1,b=-1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cost[i][j]<min){
                    min=cost[i][j];
                    a=i;
                    b=j;
                }
            }
        }

        int u=find(parent,a);
        int v=find(parent,b);

        if(u!=v){
            printf("Edge %d:(%d,%d) cost=%d\n",edge++,a+1,b+1,min);
            mincost+=min;
            parent[v]=u;
        }

        cost[a][b]=cost[b][a]=INF;
    }

    printf("Total Minimum Cost = %d\n",mincost);
}


/* ================= PRIM ================= */

void prim(){
    int n;
    printf("\nEnter number of vertices: ");
    scanf("%d",&n);

    int cost[MAX][MAX],visited[MAX]={0};

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    visited[0]=1;
    int edge=1,mincost=0;

    while(edge<n){
        int min=INF,a=-1,b=-1;

        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=0;j<n;j++){
                    if(!visited[j] && cost[i][j]<min){
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }

        printf("Edge %d:(%d,%d) cost=%d\n",edge++,a+1,b+1,min);
        mincost+=min;
        visited[b]=1;
    }

    printf("Total Minimum Cost = %d\n",mincost);
}


/* ================= DIJKSTRA ================= */

void dijkstra(){
    int n,start;
    printf("\nEnter number of vertices: ");
    scanf("%d",&n);

    int graph[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d",&start);

    int dist[MAX],visited[MAX]={0};

    for(int i=0;i<n;i++)
        dist[i]=graph[start-1][i];

    visited[start-1]=1;
    dist[start-1]=0;

    for(int i=0;i<n-1;i++){
        int min=INF,u=-1;

        for(int j=0;j<n;j++){
            if(!visited[j] && dist[j]<min){
                min=dist[j];
                u=j;
            }
        }

        visited[u]=1;

        for(int v=0;v<n;v++){
            if(!visited[v] && dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
        }
    }

    printf("Shortest distances:\n");
    for(int i=0;i<n;i++)
        printf("%d -> %d = %d\n",start,i+1,dist[i]);
}


/* ================= MAIN MENU ================= */

int main(){
    int choice;

    while(1){
        printf("\n===== MENU =====\n");
        printf("1. Fractional Knapsack\n");
        printf("2. Job Sequencing\n");
        printf("3. Kruskal\n");
        printf("4. Prim\n");
        printf("5. Dijkstra\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: fractionalKnapsack(); break;
            case 2: jobSequencing(); break;
            case 3: kruskal(); break;
            case 4: prim(); break;
            case 5: dijkstra(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
