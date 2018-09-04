#include<stdio.h>
#include<stdlib.h>
struct Node{
    int max;
    int min;
}data[1000000];
int MAXlen,cnt;
int two[16] = {1,2,4,8,16,32,64,128,256,512,1024};
void update(int x,int y,int val,int pos,int nowx,int nowy,int nowlen){
    int type,nextx,nexty,MAX=-2147483000,MIN=2147483000,i,tmp,tmp2;
    if(nowlen == 0){
        data[pos].max = val;
        data[pos].min = val;
        return ;
    } 
    if(x < nowx+nowlen && y < nowy+nowlen){type = 1;nextx = nowx;nexty = nowy;}
    else if(x >= nowx+nowlen && y < nowy+nowlen){type = 2;nextx = nowx+nowlen;nexty = nowy;}
    else if(x < nowx+nowlen && y >= nowy+nowlen){type = 3;nextx = nowx;nexty = nowy+nowlen;}
    else if(x >= nowx+nowlen && y >= nowy+nowlen){type = 4;nextx = nowx+nowlen;nexty = nowy+nowlen;}
    update(x,y,val,pos*4+type,nextx,nexty,nowlen/2);
    for(i=1;i<=4;i++){
        tmp = data[pos*4+i].max;
        tmp2 = data[pos*4+i].min;
        if(tmp > MAX)MAX = tmp;
        if(tmp2 < MIN)MIN = tmp2;
    }
    data[pos].max = MAX;
    data[pos].min = MIN;
}
void update2(int x,int y,int val,int pos,int nowx,int nowy,int nowlen){
    int type,nextx,nexty,MAX=-2147483000,MIN=2147483000,i,tmp;
    if(nowlen == 0){
        data[pos].min = val;
        return ;
    } 
    if(x < nowx+nowlen && y < nowy+nowlen){type = 1;nextx = nowx;nexty = nowy;}
    else if(x >= nowx+nowlen && y < nowy+nowlen){type = 2;nextx = nowx+nowlen;nexty = nowy;}
    else if(x < nowx+nowlen && y >= nowy+nowlen){type = 3;nextx = nowx;nexty = nowy+nowlen;}
    else if(x >= nowx+nowlen && y >= nowy+nowlen){type = 4;nextx = nowx+nowlen;nexty = nowy+nowlen;}
    update2(x,y,val,pos*4+type,nextx,nexty,nowlen/2);
    for(i=1;i<=4;i++){
        tmp = data[pos*4+i].min;
        if(tmp < MIN)MIN = tmp;
    }
   
    data[pos].min = MIN;
}
int findMax(int x1,int y1,int x2,int y2,int x,int y,int nowlen,int pos){
    int nx,ny,tmp,MAX=-2147483600;
    if(x + 2*nowlen-1 == x2 && y + 2*nowlen-1 == y2 && x == x1 && y == y1)
        return data[pos].max;
    if(nowlen == 0)
        return data[pos].max;
    nx = x+nowlen;
    ny = y+nowlen;
    if(x1 < nx && y1 < ny && x2 < nx && y2 < ny){
        return findMax(x1,y1,x2,y2,x,y,nowlen/2,pos*4+1);
    }
    if(x1 >= nx && y1 < ny && x2 >= nx && y2 < ny){
        return findMax(x1,y1,x2,y2,nx,y,nowlen/2,pos*4+2);
    }
    if(x1 < nx && y1 >= ny && x2 < nx && y2 >= ny){
        return findMax(x1,y1,x2,y2,x,ny,nowlen/2,pos*4+3);
    }
    if(x1 >= nx && y1 >= ny && x2 >= nx && y2 >= ny){
        return findMax(x1,y1,x2,y2,nx,ny,nowlen/2,pos*4+4);
    }    
    if(x1 < nx && y1 < ny && x2 >= nx && y2 < ny){
        tmp = findMax(x1,y1,nx-1,y2,x,y,nowlen/2,pos*4+1);
        if(tmp > MAX)MAX = tmp;
        tmp = findMax(nx,y1,x2,y2,nx,y,nowlen/2,pos*4+2);
        if(tmp > MAX)MAX = tmp;
        return MAX;
    }        
    if(x1 < nx && y1 < ny && x2 < nx && y2 >= ny){
        tmp = findMax(x1,y1,x2,ny-1,x,y,nowlen/2,pos*4+1);
        if(tmp > MAX)MAX = tmp;
        tmp = findMax(x1,ny,x2,y2,x,ny,nowlen/2,pos*4+3);
        if(tmp > MAX)MAX = tmp;
        return MAX;
    }
    if(x1 >= nx && y1 < ny && x2 >= nx && y2 >= ny){
        tmp = findMax(x1,y1,x2,ny-1,nx,y,nowlen/2,pos*4+2);
        if(tmp > MAX)MAX = tmp;
        tmp = findMax(x1,ny,x2,y2,nx,ny,nowlen/2,pos*4+4);
        if(tmp > MAX)MAX = tmp;
        return MAX;
    }
    if(x1 < nx && y1 >= ny && x2 >= nx && y2 >= ny){
        tmp = findMax(x1,y1,nx-1,y2,x,ny,nowlen/2,pos*4+3);
        if(tmp > MAX)MAX = tmp;
        tmp = findMax(nx,y1,x2,y2,nx,ny,nowlen/2,pos*4+4);
        if(tmp > MAX)MAX = tmp;
        return MAX;
    }
    if(x1 < nx && y1 < ny && x2 >= nx && y2 >= ny){
        tmp = findMax(x1,y1,nx-1,ny-1,x,y,nowlen/2,pos*4+1);
        if(tmp > MAX)MAX = tmp;
        tmp = findMax(nx,y1,x2,ny-1,nx,y,nowlen/2,pos*4+2);
        if(tmp > MAX)MAX = tmp;
        tmp = findMax(x1,ny,nx-1,y2,x,ny,nowlen/2,pos*4+3);
        if(tmp > MAX)MAX = tmp;
        tmp = findMax(nx,ny,x2,y2,nx,ny,nowlen/2,pos*4+4);
        if(tmp > MAX)MAX = tmp;
        return MAX;
    }
}
int findMin(int x1,int y1,int x2,int y2,int x,int y,int nowlen,int pos){
    int nx,ny,tmp,MIN=2147483600;
    if(x + 2*nowlen-1 == x2 && y + 2*nowlen-1 == y2 && x == x1 && y == y1)
        return data[pos].min;
    if(nowlen == 0)
        return data[pos].min;        
    nx = x+nowlen;
    ny = y+nowlen;
    if(x1 < nx && y1 < ny && x2 < nx && y2 < ny){
        return findMin(x1,y1,x2,y2,x,y,nowlen/2,pos*4+1);
    }
    if(x1 >= nx && y1 < ny && x2 >= nx && y2 < ny){
        return findMin(x1,y1,x2,y2,nx,y,nowlen/2,pos*4+2);
    }
    if(x1 < nx && y1 >= ny && x2 < nx && y2 >= ny){
        return findMin(x1,y1,x2,y2,x,ny,nowlen/2,pos*4+3);
    }
    if(x1 >= nx && y1 >= ny && x2 >= nx && y2 >= ny){
        return findMin(x1,y1,x2,y2,nx,ny,nowlen/2,pos*4+4);
    }    
    if(x1 < nx && y1 < ny && x2 >= nx && y2 < ny){
        tmp = findMin(x1,y1,nx-1,y2,x,y,nowlen/2,pos*4+1);
        if(tmp < MIN)MIN = tmp;
        tmp = findMin(nx,y1,x2,y2,nx,y,nowlen/2,pos*4+2);
        if(tmp < MIN)MIN = tmp;
        return MIN;
    }        
    if(x1 < nx && y1 < ny && x2 < nx && y2 >= ny){
        tmp = findMin(x1,y1,x2,ny-1,x,y,nowlen/2,pos*4+1);
        if(tmp < MIN)MIN = tmp;
        tmp = findMin(x1,ny,x2,y2,x,ny,nowlen/2,pos*4+3);
        if(tmp < MIN)MIN = tmp;
        return MIN;
    }
    if(x1 >= nx && y1 < ny && x2 >= nx && y2 >= ny){
        tmp = findMin(x1,y1,x2,ny-1,nx,y,nowlen/2,pos*4+2);
        if(tmp < MIN)MIN = tmp;
        tmp = findMin(x1,ny,x2,y2,nx,ny,nowlen/2,pos*4+4);
        if(tmp < MIN)MIN = tmp;
        return MIN;
    }       
    if(x1 < nx && y1 >= ny && x2 >= nx && y2 >= ny){
        tmp = findMin(x1,y1,nx-1,y2,x,ny,nowlen/2,pos*4+3);
        if(tmp < MIN)MIN = tmp;
        tmp = findMin(nx,y1,x2,y2,nx,ny,nowlen/2,pos*4+4);
        if(tmp < MIN)MIN = tmp;
        return MIN;
    }    
    if(x1 < nx && y1 < ny && x2 >= nx && y2 >= ny){
        tmp = findMin(x1,y1,nx-1,ny-1,x,y,nowlen/2,pos*4+1);
        if(tmp < MIN)MIN = tmp;
        tmp = findMin(nx,y1,x2,ny-1,nx,y,nowlen/2,pos*4+2);
        if(tmp < MIN)MIN = tmp;
        tmp = findMin(x1,ny,nx-1,y2,x,ny,nowlen/2,pos*4+3);
        if(tmp < MIN)MIN = tmp;
        tmp = findMin(nx,ny,x2,y2,nx,ny,nowlen/2,pos*4+4);
        if(tmp < MIN)MIN = tmp;
        return MIN;
    }
}
int main(){
    int n,m,x1,x2,y1,y2,tmp,i,j,q,x,y,v,len;
    char ch;
    scanf("%d%d",&n,&n);
    for(i=0;i<1000000;i++){
        data[i].max = -2147483000;
        data[i].min = 2147483000;
    }
    for(i=0;i<10;i++){
        if(two[i] >= n-1 && two[i] >= m-1){
            len = two[i];
            break;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&tmp);
            update(i,j,tmp,0,0,0,len);
        }
    }
    scanf("%d%*c",&q);
    while(q--){
        cnt = 0;
        scanf("%c",&ch);
        if(ch == 'q'){
            scanf("%d%d%d%d%*c",&x1,&y1,&x2,&y2);
            printf("%d %d\n",findMax(x1-1,y1-1,x2-1,y2-1,0,0,len,0),findMin(x1-1,y1-1,x2-1,y2-1,0,0,len,0));
        }
        if(ch == 'c'){
            scanf("%d%d%d%*c",&x,&y,&v);
            update(x-1,y-1,v,0,0,0,len);
        }
    }
    return 0;
}
