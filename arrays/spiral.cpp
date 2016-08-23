vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	int i,j;
	int ibeg = 0;
	int iend = A.size() - 1;
	int jbeg = 0, jend = A[0].size() - 1;
	
	while (ibeg <= iend && jbeg <= jend) {
	    j = jbeg;
	    
	    while (j <= jend) {
	        result.push_back(A[ibeg][j]);
	        j++;
	    }
	    
	    ibeg++;
	    i = ibeg;
	    
	    while (i <= iend) {
	        result.push_back(A[i][jend]);
	        i++;
	    }
	    
	    jend--;
	   
	   if (ibeg > iend || jbeg > jend)
	        break;
	    
	    j = jend;
	    
	    while (j>=jbeg) {
	        result.push_back(A[iend][j]);
	        j--;
	    }
	    
	    iend--;
	    i = iend;
	    
	    while (i>=ibeg) {
	        result.push_back(A[i][jbeg]);
	        i--;
	    }
	    
	    jbeg++;
	}
	
	return result;
   
}
