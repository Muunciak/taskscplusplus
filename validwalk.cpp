bool isValidWalk(std::vector<char> walk) {
  //your code here
  int n=0,s=0,e=0,w=0,size=0;
  for(int i=0;i<(int)(walk.size());i++){
    switch(walk[i]){
      case 'n':n++;size++;break;
      case 's':s++;size++;break;
      case 'e':e++;size++;break;
      case 'w':w++;size++;break;
        }
    }
    if(size==10 && n-s==0 && e-w==0)
      return true;
      else
      return false; 
  }
