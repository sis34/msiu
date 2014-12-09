#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double iris[150][8], W[2][5][6],Wn[2][5][6], y[3][6], prir = 0, obvib[90][5],tvib[60][5],d[90][3],dt[60][3],osh[3],sosh = 100, kor = 1,sigm[2][5],lol;
int tm = 0, oy[3], max;

double nu(int j, int l){
	int i;
	prir = 0;
	
	for(i = 0; i<5; i++){
		if ((l==1) &&(i>3)) break;
		prir += W[l][j][i]*y[l][i];
	}
	return prir;
}

void vvod(FILE *t){
	int i,j;

	for (i = 0; i<150; i++) {
		iris[i][0] = 1;
		fscanf(t,"%lf %lf %lf %lf %lf %lf %lf\n", &iris[i][1], &iris[i][2], &iris[i][3], &iris[i][4], &iris[i][5], &iris[i][6], &iris[i][7]);
	}

	for (i = 0; i< 30; i++){
		for (j= 0; j<5; j++){
			obvib[i][j] = iris[i][j];
			obvib[i+30][j] = iris[i+50][j];
			obvib[i+60][j] = iris[i+100][j];
		}
		for(j = 0; j<3;j++){
			d[i][j] = iris[i][j+5];
			d[i+30][j] = iris[i+50][j+5];
			d[i+60][j] = iris[i+100][j+5];
		}
	}//obvib

	for (i = 0; i< 20; i++){
		for (j= 0; j<5; j++){
			tvib[i][j] = iris[i+30][j];
			tvib[i+20][j] = iris[i+80][j];
			tvib[i+40][j] = iris[i+130][j];
		}
		for(j = 0; j<3;j++){
			dt[i][j] = iris[i+30][j+5];
			dt[i+20][j] = iris[i+80][j+5];
			dt[i+40][j] = iris[i+130][j+5];
		}
	}//tvib

	for (i = 0; i<3;i++){
		for (j = 0; j<5; j++) W[0][i][j] = ((double)rand()/RAND_MAX - 0.5)*2;
	}
	for (i = 0; i<3;i++){
		for (j = 0; j<4; j++) W[1][i][j] = ((double)rand()/RAND_MAX - 0.5)*2;
	}

	for(i=0;i<3;i++) oy[i] = 0;
}

int ism(){
	int l,i,j;
	prir = 0;
	
	for(l = 0; l<2; l++){
		for(i = 0; i<3; i++){
			for(j = 0; j<5; j++) {
				if ((l==1)&&(j>3)) break;
				prir+= pow(Wn[l][i][j] -  W[l][i][j],2);
			}
		}
	} 

	if (pow(prir,0.5) < pow(10,-4)) return 1;

	return 0;
}

double ksi(int l,int j){
	int i;
	double prir = 0;

    if (l == 1) return osh[j]*exp(nu(j,l))/(pow(exp(nu(j,l))+1,2));
	for(i = 0; i<3; i++) prir += sigm[l+1][i]*W[l+1][i][j+1];////////??????
    return prir * exp(nu(j,l))/(pow(exp(nu(j,l))+1,2));//A
}

void vivod(){
	int i,j,l,k;

	printf("========================================================\n");
	for(i=0;i<3;i++){printf("OSH[%d]=%d time=%d\n", i, oy[i], tm);}
    printf("========================================================\n");
	printf("oshOBYCH= %lf\n\n",sosh/90*100 );

	for(l=0;l<3;l++) oy[l] = 0;

	for(i = 0; i<60; i++){
		 for(k=0;k<5;k++) y[0][k] = tvib[i][k];
        for(l=0;l<2;l++) {
            k=0;
            if (l==0)	{y[l+1][0] = 1; k=1;}
            for(j = 0; j<3; j++) {
                y[l+1][j+k] = 1/(1+exp(-nu(j,l))); //??????
            }
        }

        prir = y[2][0];
        max = 0;
        for(j = 1; j<3;j++) if (y[2][j]>prir) { prir = y[2][j]; max = j;}
        for(j = 0; j<3; j++) if (j==max) {osh[j] = 1;} else {osh[j] = 0;}
        for(j = 0; j<3; j++) if (osh[j] != dt[i][j]) oy[j]++;
	}

	sosh = 0.0;
	printf("========================================================\n");
	for(i=0;i<3;i++){sosh+=oy[i]; printf("OSH[%d]=%d ", i, oy[i]);}//otl
	sosh = sosh/60*100;
	printf("\n");
	printf("========================================================\n");

	printf("oshibok TESTa iz 100 procentov = %lf\n\n", sosh);
}

int main(){

	FILE *t;
	t = fopen("init.txt","r");
	srand(time(NULL));
	int i,j,k,l;
	vvod(t);

	while(1){ 

			kor*= 0.999;
			 
		for(l=0;l<2;l++){
			for (i = 0; i<3;i++){
				for (j = 0; j<5; j++) {
					if ((l==1)&&(j>3)) break;
					Wn[l][i][j] = W[l][i][j];
				}
			}////W->Wn
		}

		for (j = 0;j<3; j++) {osh[j] = 0; oy[j] = 0;}

		for (i = 0; i<90; i++){

			for(k=0;k<5;k++) y[0][k] = obvib[i][k];
			for(l=0;l<2;l++) {
                k=0;
                if (l==0)	{y[l+1][0] = 1; k=1;}
				for(j = 0; j<3; j++) {
                    y[l+1][j+k] = 1/(1+exp(-nu(j,l))); //??????
				}
			}

			for(j = 0; j<3;j++) osh[j] = d[i][j]-y[2][j];//E()

			for(l=1;l>=0;l--){
				for(j = 0;j<3;j++) sigm[l][j] = ksi(l,j);
			}

			for(l=0;l<2;l++){
				for(j = 0;j<3;j++){
					for (k = 0; k< 5; k++){
						if ((l == 1)&&(k > 3)) break;
						W[l][j][k] += 0.4*kor*sigm[l][j]*y[l][k];
					}
				}//sinop
			}
		}
		//podchet


		if (ism() == 1) break;

		tm++;
	}	

	sosh = 0.0;

    for(i =0; i<90; i++){
        for(k=0;k<5;k++) y[0][k] = obvib[i][k];
        for(l=0;l<2;l++) {
            k=0;
            if (l==0)	{y[l+1][0] = 1; k=1;}
            for(j = 0; j<3; j++) {
                y[l+1][j+k] = 1/(1+exp(-nu(j,l))); //??????
            }
        }

        prir = y[2][0];
        max = 0;
        for(j = 1; j<3;j++) if (y[2][j]>prir) { prir = y[2][j]; max = j;}
        for(j = 0; j<3; j++) if (j==max) {osh[j] = 1;} else {osh[j] = 0;}
        for(j = 0; j<3; j++) if (osh[j] != d[i][j]) {oy[j]++;
        printf("%lf = %lf \t", osh[j],d[i][j]);
        printf("\n");}
    }

	for(i = 0; i<3;i++) sosh += oy[i];

	vivod();
	fclose(t);
	return 0;
}
