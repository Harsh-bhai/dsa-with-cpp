# UNLABLED nodes
1.no. of tree combination with given no. of nodes(catalan no.)[t(n)] = (2n^Cn)/(n+1)  
2.height start from 0  
3.level start from 1  
4.no. of trees with max height=2^(n-1)  
5.alternate catalan no. = sum(t(i-1)*t(n-i)) , where i starting from 1  (or t(i)*t(n-i) for understanding purpose)

# LABLED nodes
catalan no.= t(n)=(2n^Cn) * n!/(n+1)  , n! is due to they can arrange in n! ways.


# NO. OF NODES w.r.t. HEIGHT in Binary Tree
min no.of nodes=height + 1
max no.of nodes=2^(h+1) - 1


# calculate HEIGHT w.r.t. NO. OF NODES
MAX HEIGHT=n-1  
MIN HEIGHT=log(n+1)-1  
i.e., Height of Binary Tree ranges from O(logn) to O(n).  
No. of Nodes with degree 0 = No. of Nodes with degree 2 + 1  
i.e., n(degree(0))= n(degree(2)) + 1