void DFS( vector<int> graph[] , int node , int d )
{
    // marking the node as visited
    vis[node] = 1 ;


    // if the distance from root is greater then maximum Distance then updating the maximum value of distance
    // also storing the maxNode no. as this node is now at the farthest distance
    if( d > maxD )
    {
        maxNode = node ;
        maxD = d ;
    }

     // applying the standard dfs 
    for( auto x : graph[node] )
    {
        if( vis[x] == 0 )
        {
            DFS( graph , x , d+1 ) ;
        }
    }

}




// Applyting DFS from node 1
DFS( graph , 1 , 1 ) ;
// we could have choosen any node in the graph but for simplicity we have choosen node 1


// making every node unvisited as we will be applying DFS
maxD = -1 ;
for( int i = 1 ; i<=8 ; i++ )
{
    vis[i] = 0 ;
}

// applying the dfs for the second time as this will give the diameter of the tree
DFS( graph , maxNode , 1  ) ;


// Now printing the maximum diameter of the tree
cout<<maxD<<" is the diameter of the tree "<<endl;

    



