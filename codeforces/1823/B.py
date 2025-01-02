l=lambda:map(int,input().split())
t,=l()
while t:
 t-=1;n,k=l();i=m=0
 for x in l():i+=1;m+=x%k!=i%k
 print(m and'-1'[m<3:])
				   	  		      		 	  	 			