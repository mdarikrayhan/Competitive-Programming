void main(){
	float k=((float)Stdio.stdin.gets())*acos(0.0)/90,x,y;
	sscanf(Stdio.stdin.gets(),"%f %f",x,y);
	write((x*cos(k)-y*sin(k))+" "+(y*cos(k)+x*sin(k))+"\n");
}
