vector<int> getRow(int a) {
    vector<int>B;
    vector<int>A = {{1}};
    
    for(int i=0;i<a;i++){
        if(A.size()){
            for(auto itr= A.begin();itr<=A.end();itr++){
                if(itr==A.begin() || itr==A.end())
                    B.push_back(1);
                else
                    B.push_back(*itr + *(itr-1));
            }
            A.clear();
        }
        else{
            for(auto itr = B.begin();itr<=B.end();itr++){
                if(itr==B.begin() || itr==B.end())
                    A.push_back(1);
                else 
                    A.push_back(*itr + *(itr-1));
            }
            B.clear();
        }
    }
    return (A.size()?A:B);
}
