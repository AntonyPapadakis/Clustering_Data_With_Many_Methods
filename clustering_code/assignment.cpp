//
// Created by antonis on 30/11/2018.
//

#include "assignment.h"
#include <bitset>
#include "hyper.h"



void assignment::out(argClass args,string algo,string opath){
    ofstream output; //output stream


    //output
    output.open(opath);

    output << "Algorithm: "<< algo <<"\n";

    output<<"Metric: "<<metric<<"\n";

    for(int j=0;j<centroid_num;j++){

        output<<"cluster-"<<j<<" ";

        if (clusters[j].counter==0 && clusters[j].keep_last_counter!=0){
            clusters[j].counter = clusters[j].keep_last_counter;
        }

        for(int i=0; i<clusters[j].counter;i++){

            output<<clusters[j].cluster_data_id[i]<<" ";

        }
        output<<"\n";
    }

/*
    output<<"clustering time: "<<clustering_time;
    output<<"silhouette: [";
    for(int j=0;j<centroid_num;j++) {

        output<<clusters[j].si<<",";

    }
    output<<sil<<"]\n\n";
    */
/*
    for(int j=0;j<centroid_num;j++) {
        output<<"cluster-"<<j<<"{ ";

        for(int i=0; i<clusters[j].counter;i++){
            for(int h=0; h<clusters[j].cluster_data[i].size();h++) {
                output << clusters[j].cluster_data[i][h] << " ";
            }
            output<<"}\n\n";
        }
    }
*/



}

void assignment::m1(argClass args,  initialization init, assignment assign){
    int count=0;
    item * i;
    int keep_nums[centroid_num];

    clock_t begin = clock();


    while (done==false && count<30){
        if(count==0 )   i = Loyds_assignment( args.get_data() ,args.get_datai() , NULL) ;
        else         i = Loyds_assignment(   args.get_data(), args.get_datai() , i) ;


        if(count>0){
            done=true;
            for(int j=0;j<centroid_num;j++){
                if(keep_nums[j]!=clusters[j].counter) {
                    if(keep_nums[j]>clusters[j].counter+40 || keep_nums[j]<clusters[j].counter-40) {
                        done =false;
                        break;
                    }
                }
            }
        }

        for(int j=0;j<centroid_num;j++){
            keep_nums[j]=clusters[j].counter;
        }

        for(int j=0;j<centroid_num;j++){
            keep_nums[j]=clusters[j].counter;
            cout<<clusters[j].counter<< " e ";
        }


        count++;
        cout<<" update number "<< count<<endl;
        if(done) {
            cout<<" clustering complete "<<endl;
            cout << silhouette() << " okk " << endl;
            break;
        }

        update_centers_kmeans();
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    clustering_time = elapsed_secs;
    out(args,"I1A1U1","out1");

}

void assignment::m2(argClass args,  initialization init, assignment assign){
    int count=0;
    item * i;
    int keep_nums[centroid_num];

    clock_t begin = clock();

    while (done==false && count<30){

        if(count==0 )   i = LSH(  args  ,init,assign, NULL) ;
        else         i = LSH(  args  ,init,assign, i) ;

        if(count>0){
            done=true;
            for(int j=0;j<centroid_num;j++){
                if(keep_nums[j]!=clusters[j].counter) {
                    if(keep_nums[j]>clusters[j].counter+3 || keep_nums[j]<clusters[j].counter-3) {
                        done =false;
                        break;
                    }
                }
            }
        }

        for(int j=0;j<centroid_num;j++){
            keep_nums[j]=clusters[j].counter;
            cout<<clusters[j].counter<< " e ";
        }


        count++;

        if(done || count==15) {
            cout<<" clustering complete "<<endl;
            cout << silhouette() << " okk " << endl;
            fflush(stdout);
            break;
        }
        else{
            cout<<" update number "<< count<<endl;

            update_centers_kmeans();
        }
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    clustering_time = elapsed_secs;
    out(args,"I1A2U1","out2");

}
void assignment::m3(argClass args,  initialization init, assignment assign){
    int count=0;
    item * i;
    int keep_nums[centroid_num];

    clock_t begin = clock();

    while (done==false && count<30){

        if(count==0 )   i = cube(  args  ,init,assign, NULL) ;
        else         i = cube(  args  ,init,assign, i) ;


        if(count>0){
            done=true;
            for(int j=0;j<centroid_num;j++){
                if(keep_nums[j]!=clusters[j].counter) {
                    if(keep_nums[j]>clusters[j].counter+3 || keep_nums[j]<clusters[j].counter-3) {
                        done =false;
                        break;
                    }
                }
            }
        }

        for(int j=0;j<centroid_num;j++){
            keep_nums[j]=clusters[j].counter;
            cout<<clusters[j].counter<< " e ";
        }

        cout<<"aaa1"<<endl;
        count++;
        cout<<" update number "<< count<<endl;
        if(done) {
            cout<<" clustering complete "<<endl;
            cout << silhouette() << " okk " << endl;
            break;
        }

        update_centers_kmeans();

    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    clustering_time = elapsed_secs;
    out(args,"I1A3U1","out3");
}
void assignment::m4(argClass args,  initialization init, assignment assign){

    int count=0;
    item * i;
    int keep_nums[centroid_num];

    clock_t begin = clock();

    while (done==false && count<30){
        if(count==0 )   i = Loyds_assignment( args.get_data() ,args.get_datai() , NULL) ;
        else         i = Loyds_assignment(   args.get_data(), args.get_datai() , i) ;

        if(count>0){
            done=true;
            for(int j=0;j<centroid_num;j++){
                if(keep_nums[j]!=clusters[j].counter) {
                    if(keep_nums[j]>clusters[j].counter+3 || keep_nums[j]<clusters[j].counter-3) {
                        done =false;
                        break;
                    }
                }
            }
        }

        for(int j=0;j<centroid_num;j++){
            keep_nums[j]=clusters[j].counter;
            cout<<clusters[j].counter<< " e ";
        }


        count++;
        cout<<" update number "<< count<<endl;
        if(done) {
            cout<<" clustering complete "<<endl;
            cout << silhouette() << " okk " << endl;
            break;
        }

        update_centers_kmedoids();

    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    clustering_time = elapsed_secs;
    out(args,"I1A1U2","out4");

}

void assignment::m5(argClass args,  initialization init, assignment assign){
    int count=0;
    item * i;
    int keep_nums[centroid_num];

    clock_t begin = clock();

    while (done==false && count<30){
        if(count==0 )   i = LSH(  args  ,init,assign, NULL) ;
        else         i = LSH(  args  ,init,assign, i) ;

        if(count>0){
            done=true;
            for(int j=0;j<centroid_num;j++){
                if(keep_nums[j]!=clusters[j].counter) {
                    if(keep_nums[j]>clusters[j].counter+3 || keep_nums[j]<clusters[j].counter-3) {
                        done =false;
                        break;
                    }
                }
            }
        }

        for(int j=0;j<centroid_num;j++){
            keep_nums[j]=clusters[j].counter;
            cout<<clusters[j].counter<< " e ";
        }


        count++;
        cout<<" update number "<< count<<endl;
        if(done) {
            cout<<" clustering complete "<<endl;
            cout << silhouette() << " okk " << endl;
            break;
        }

        update_centers_kmedoids();

    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    clustering_time = elapsed_secs;
    out(args,"I1A2U2","out5");

}
void assignment::m6(argClass args,  initialization init, assignment assign){
    int count=0;
    item * i;
    int keep_nums[centroid_num];

    clock_t begin = clock();

    while (done==false && count<30){
        if(count==0 )   i = cube(  args  ,init,assign, NULL) ;
        else         i = cube(  args  ,init,assign, i) ;

        if(count>0){
            done=true;
            for(int j=0;j<centroid_num;j++){
                if(keep_nums[j]!=clusters[j].counter) {
                    if(keep_nums[j]>clusters[j].counter+3 || keep_nums[j]<clusters[j].counter-3) {
                        done =false;
                        break;
                    }
                }
            }
        }

        for(int j=0;j<centroid_num;j++){
            keep_nums[j]=clusters[j].counter;
            cout<<clusters[j].counter<< " e ";
        }


        count++;
        cout<<" update number "<< count<<endl;
        if(done) {
            cout<<" clustering complete "<<endl;
            cout << silhouette() << " okk " << endl;
            break;
        }

        update_centers_kmedoids();
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    clustering_time = elapsed_secs;
    out(args,"I1A3U2","out6");
}

void assignment::m7(argClass args,  initialization init, assignment assign){
    int count=0;
    item * i;
    int keep_nums[centroid_num];

    clock_t begin = clock();

    while (done==false && count<20){
        if(count==0 )   i = Loyds_assignment( args.get_data() ,args.get_datai() , NULL) ;
        else         i = Loyds_assignment(   args.get_data(), args.get_datai() , i) ;

        if(count>0){
            done=true;

            for(int j=0;j<centroid_num;j++){
                if(keep_nums[j]!=clusters[j].counter) {
                    if(keep_nums[j]>clusters[j].counter+3 || keep_nums[j]<clusters[j].counter-3) {
                        done =false;
                        break;
                    }
                }
            }
        }
        for(int j=0;j<centroid_num;j++){
            keep_nums[j]=clusters[j].counter;
            cout<<clusters[j].counter<< " e "<<endl;
        }


        count++;
        cout<<" update number "<< count<<endl;
        if(done || count==20) {
            cout<<" clustering complete "<<endl;
            cout << silhouette() << " okk " << endl;
            break;
        }

        update_centers_kmeans();
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    clustering_time = elapsed_secs;
    out(args,"I2A1U1","out7");

}

void assignment::m8(argClass args,  initialization init, assignment assign){
    int count=0;
    item * i;
    int keep_nums[centroid_num];

    clock_t begin = clock();

    while (done==false && count<30){
        if(count==0 )   i = LSH(  args  ,init,assign, NULL) ;
        else         i = LSH(  args  ,init,assign, i) ;

        if(count>0){
            done=true;
            for(int j=0;j<centroid_num;j++){
                if(keep_nums[j]!=clusters[j].counter) {
                    if(keep_nums[j]>clusters[j].counter+3 || keep_nums[j]<clusters[j].counter-3) {
                        done =false;
                        break;
                    }
                }
            }
        }

        for(int j=0;j<centroid_num;j++){
            keep_nums[j]=clusters[j].counter;
            cout<<clusters[j].counter<< " e ";
        }


        count++;
        cout<<" update number "<< count<<endl;
        if(done) {
            cout<<" clustering complete "<<endl;
            cout << silhouette() << " okk " << endl;
            break;
        }

        update_centers_kmeans();
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    clustering_time = elapsed_secs;
    out(args,"I2A2U1","out8");

}
void assignment::m9(argClass args,  initialization init, assignment assign){
    int count=0;
    item * i;
    int keep_nums[centroid_num];

    clock_t begin = clock();

    while (done==false && count<30){
        if(count==0 )   i = cube(  args  ,init,assign, NULL) ;
        else         i = cube(  args  ,init,assign, i) ;

        if(count>0){
            done=true;
            for(int j=0;j<centroid_num;j++){
                if(keep_nums[j]!=clusters[j].counter) {
                    if(keep_nums[j]>clusters[j].counter+3 || keep_nums[j]<clusters[j].counter-3) {
                        done =false;
                        break;
                    }
                }
            }
        }

        for(int j=0;j<centroid_num;j++){
            keep_nums[j]=clusters[j].counter;
            cout<<clusters[j].counter<< " e ";
        }


        count++;
        cout<<" update number "<< count<<endl;
        if(done) {
            cout<<" clustering complete "<<endl;
            cout << silhouette() << " okk " << endl;
            break;
        }

        update_centers_kmeans();
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    clustering_time = elapsed_secs;
    out(args,"I2A3U1","out9");
}
void assignment::m10(argClass args,  initialization init, assignment assign){

    int count=0;
    item * i;
    int keep_nums[centroid_num];

    clock_t begin = clock();

    while (done==false && count<30){
        if(count==0 )   i = Loyds_assignment( args.get_data() ,args.get_datai() , NULL) ;
        else         i = Loyds_assignment(   args.get_data(), args.get_datai() , i) ;

        if(count>0){
            done=true;
            for(int j=0;j<centroid_num;j++){
                if(keep_nums[j]!=clusters[j].counter) {
                    if(keep_nums[j]>clusters[j].counter+3 || keep_nums[j]<clusters[j].counter-3) {
                        done =false;
                        break;
                    }
                }
            }
        }

        for(int j=0;j<centroid_num;j++){
            keep_nums[j]=clusters[j].counter;
            cout<<clusters[j].counter<< " e ";
        }


        count++;
        cout<<" update number "<< count<<endl;
        if(done) {
            cout<<" clustering complete "<<endl;
            cout << silhouette() << " okk " << endl;
            break;
        }

        update_centers_kmedoids();
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    clustering_time = elapsed_secs;
    out(args,"I2A1U2","out10");

}
void assignment::m11(argClass args,  initialization init, assignment assign){
    int count=0;
    item * i;
    int keep_nums[centroid_num];

    clock_t begin = clock();

    while (done==false && count<30){
        if(count==0 )   i = LSH(  args  ,init,assign, NULL) ;
        else         i = LSH(  args  ,init,assign, i) ;

        if(count>0){
            done=true;
            for(int j=0;j<centroid_num;j++){
                if(keep_nums[j]!=clusters[j].counter) {
                    if(keep_nums[j]>clusters[j].counter+3 || keep_nums[j]<clusters[j].counter-3) {
                        done =false;
                        break;
                    }
                }
            }
        }

        for(int j=0;j<centroid_num;j++){
            keep_nums[j]=clusters[j].counter;
            cout<<clusters[j].counter<< " e ";
        }


        count++;
        cout<<" update number "<< count<<endl;
        if(done) {
            cout<<" clustering complete "<<endl;
            cout << silhouette() << " okk " << endl;
            break;
        }

        update_centers_kmedoids();
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    clustering_time = elapsed_secs;
    out(args,"I2A2U2","out11");

}
void assignment::m12(argClass args,  initialization init, assignment assign){
    int count=0;
    item * i;
    int keep_nums[centroid_num];

    clock_t begin = clock();

    while (done==false && count<30){
        if(count==0 )   i = cube(  args  ,init,assign, NULL) ;
        else         i = cube(  args  ,init,assign, i) ;

        if(count>0){
            done=true;
            for(int j=0;j<centroid_num;j++){
                if(keep_nums[j]!=clusters[j].counter) {
                    if(keep_nums[j]>clusters[j].counter+3 || keep_nums[j]<clusters[j].counter-3) {
                        done =false;
                        break;
                    }
                }
            }
        }

        for(int j=0;j<centroid_num;j++){
            keep_nums[j]=clusters[j].counter;
            cout<<clusters[j].counter<< " e ";
        }


        count++;
        cout<<" update number "<< count<<endl;
        if(done) {
            cout<<" clustering complete "<<endl;
            cout << silhouette() << " okk " << endl;
            break;
        }

        update_centers_kmedoids();
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    clustering_time = elapsed_secs;
    out(args,"I2A3U2","out12");
}


double assignment::silhouette(){
    double a;
    double b;
    item p,q;
    double si=0.0;
    double silhouette_mean=0.0;
    double total=-1;
    int keep_times=0;

    for(int i=0; i<centroid_num; i++){
        if(clusters[i].counter>0) {

            double min_2centr = 9999;   //2nd closest centroid
            double min=9999;
            int closest2 = 0;//2nd closest centroid

            int closest = 0;
            double dist;   //distance for 2nd closest centroid
            p.set_coord(clusters[i].centroid);

            for (int h = 0; h < centroid_num; h++) {
                if (!(clusters[h].counter <= 0 || i == h)) {

                    q.set_coord(clusters[h].centroid);

                    if (metric == "euclidean") dist = eucl_dist(p, q);
                    else if (metric == "cosine") dist = cos_dist(p, q);

                    if (dist< min) {
                        min_2centr = min;
                        min = dist;
                        closest2 = closest;
                        closest = h;
                    }
                }

            }


            double sum = 0.0;
            int div=1;
            for (int h = 0; h < clusters[i].counter; h++) {
            	//div+=clusters[i].counter+clusters[closest2].counter;
            	div++;
                p.set_coord(clusters[i].cluster_data[h]);

                for (int j = 0; j < clusters[i].counter-1; j++) {

                    if (h != j) {

                        q.set_coord(clusters[i].cluster_data[j]);



                        if (metric == "euclidean") sum += eucl_dist(p, q);
                        else if (metric == "cosine") sum += cos_dist(p, q);
                    }
                }

                if(clusters[i].counter!=0) a = sum / clusters[i].counter;
                else a=sum;
                sum = 0.0;

                if (closest2!=0){     


                    for (int j = 0; j < clusters[closest2].counter-1; j++) {
                        if (h != j) {
                    		div++;

                            q.set_coord(clusters[closest2].cluster_data[j]);
                            if (metric == "euclidean") sum += eucl_dist(p, q);
                            else if (metric == "cosine") sum += cos_dist(p, q);
                        }

                    }
                }

                if(clusters[closest2].counter!=0) b = sum / clusters[closest2].counter;
                else b=sum;

                if (a< b && b!=0) si = 1 - a / b;
                else if ((a> b) && a!=1) si = b / (a - 1);
                else si = 0.0;
                silhouette_mean += si;


            }

            cout<< "calculating silhouette ..."<<endl;
            if(div!=0) silhouette_mean = silhouette_mean / div;
            clusters[i].si = silhouette_mean;
            keep_times++;
        }
    }
    for(int i=0; i<centroid_num; i++) {
        sil+=clusters[i].si;
    }
    sil = sil/centroid_num;
    cout<<"done calculating silhouette"<<endl;
    return sil;

}




assignment::assignment(int k, int num_of_points, string m,vector<double>* centroids) {

    clusters = new cluster_struct[k];

    for(int i=0; i<k;i++){

        clusters[i].centroid = centroids[i];
        clusters[i].cluster_data = new vector<double>[num_of_points+100];
        clusters[i].counter=0;
        clusters[i].keep_last_counter=0;

    }

    done = false;
    centroid_num = k;
    num_points = num_of_points;
    metric = m;

}

void assignment::clean(int k, int num_of_points, string m,vector<double>* centroids) {

    clusters = new cluster_struct[k];

    for(int i=0; i<k;i++){

        clusters[i].centroid = centroids[i];
        clusters[i].cluster_data = new vector<double>[num_of_points+100];
        clusters[i].counter=0;
        clusters[i].keep_last_counter=0;

    }

    done = false;
    centroid_num = k;
    num_points = num_of_points;
    metric = m;

}

void assignment::cl_kmeans(argClass args,  initialization init, assignment assign) {

    int count=0;
    item * i;
    int keep_nums[centroid_num];

    while (done==false && count<30){
    	fflush(stdout);
        if(count==0 )   i = LSH(  args  ,init,assign, NULL) ;
        else         i = LSH(  args  ,init,assign, i) ;

        if(count>0){
            done=true;
            for(int j=0;j<centroid_num;j++){
                if(keep_nums[j]!=clusters[j].counter) {
                    if(keep_nums[j]>clusters[j].counter+130 || keep_nums[j]<clusters[j].counter-130) {
                        done =false;
                        break;
                    }
                }
            }
        }



        for(int j=0;j<centroid_num;j++){
            keep_nums[j]=clusters[j].counter;
            cout<<clusters[j].counter<< " e "<<endl;
        }


        //return;

        count++;
        cout<<" update number "<< count<<endl;
     

        //update_centers_kmeans();
        update_centers_kmedoids();
    }
    out(args,"I2A3Udcdfsd2","out14");

}




void assignment::update_centers_kmeans(){

    for(int i=0; i<centroid_num; i++ ){

        for(int j=0; j<clusters[i].counter; j++) {
            double sum=0.0;

	        for(int h=0;h<clusters[i].cluster_data[j].size();h++){


	                sum += clusters[i].cluster_data[j][h];
	        }

            if( clusters[i].counter>0)  clusters[i].centroid[j] = sum / clusters[i].counter;
            else clusters[i].centroid[j] = sum;
            clusters[i].counter=0;
        }

    }

}

void assignment::update_centers_kmedoids() { //PAM

    done=true;
    for(int m=0; m<centroid_num; m++ ){

        double sum=0.0;
        double objective_func=0.0;
        item p,q;
        double min = 0.0;
        int cc=0;


        for(int h=0;h<clusters[m].counter-1;h++) {
            p.set_coord(clusters[m].centroid);
            q.set_coord(clusters[m].cluster_data[h]);

            if (metric == "euclidean") min += eucl_dist(p, q);
            else if (metric == "cosine") min += cos_dist(p, q);

        }

        int keep_last=0;
        for(int h=0;h<clusters[m].counter-1;h++){



            p.set_coord(clusters[m].cluster_data[h]);
			objective_func=0.0;
            for(int j=0; j<clusters[m].counter-1; j++) {
                q.set_coord(clusters[m].cluster_data[j]);

                if (metric == "euclidean") sum += eucl_dist(p, q);
                else if (metric == "cosine") sum += cos_dist(p, q);
                if( sum>min ) break;

            }
            objective_func+=sum;

            if((objective_func<min)) {
            	min = objective_func;
            	keep_last=h;
                cc++;
                done =false;
            }

       }

       if(cc>0){
       	    clusters[m].centroid=clusters[m].cluster_data[keep_last] ;
       }

       clusters[m].keep_last_counter = clusters[m].counter;
       clusters[m].counter=0;

    }

}



item* assignment::Loyds_assignment(vector<double>* points,vector<int> ids,item * old_clustering){

    if(old_clustering!=NULL) done=true;

    double temp_dist = 0.0;
    item p,q;
    item* m_range = new item[num_points+100];
    int count_range=0;
    int   final_cluster=0;


    for(int i=0; i<num_points; i++ ) {
        double min = 999999.0;
        p.set_coord(points[i]);
        p.set(ids[i]);
        final_cluster=0;

        if(old_clustering!=NULL) {

            q.set_coord(clusters[old_clustering[i].get_cluster_ball()].centroid);
            final_cluster = old_clustering[i].get_cluster_ball();
            if (metric == "euclidean") min = eucl_dist(p, q);
            else if (metric == "cosine") min = cos_dist(p, q);
        }

        for (int j = 0; j < centroid_num; j++) {

            //calculating distance
            q.set_coord(clusters[j].centroid);


            if (metric=="euclidean") temp_dist = eucl_dist(p,q);
            else if(metric == "cosine") temp_dist = cos_dist(p,q);


            if(temp_dist<min && temp_dist>0.0){

                min=temp_dist;
                final_cluster = j;
            }

        }


        clusters[final_cluster].cluster_data[clusters[final_cluster].counter]=points[i];

        clusters[final_cluster].cluster_data_id.push_back(ids[i]);

        clusters[final_cluster].counter++;



        m_range[i].set_coord(points[i]);

        m_range[i].cluster_assign(final_cluster,min);

        count_range++;


    }

    if(old_clustering!=NULL) {
        int count_d=0;

        for (int i = 0; i < old_clustering->get_size(); i++) {

            for (int j=0; j<count_range-1;j++) {


                if( m_range[j].is_equal(old_clustering[i]) && m_range[j].get_cluster_ball()!=old_clustering[i].get_cluster_ball() ){
                    count_d++;
                    break;

                }

            }

            if(count_d>190) {
                done = false;
                break;
            }
        }

    }

    return m_range;

}




item* assignment::LSH( argClass args,  initialization init, assignment assign, item* old_clustering) {

    ofstream output; //output stream
    string path,qpath,opath;

    //get parameters
    if(old_clustering!=NULL) done=true;

    int n = args.get_num_items();
    string metric = args.get_metric();
    int L = args.get_L();
    int k = args.get_hash_func_num();
    int c=1;
    double R=init.get_min()/2; //Radius given

    vector<item*> myItems; //vector storing all the items of the dataset (vectors)
    for (int i = 0; i < args.get_clusters(); i++) {
        item* p = new item(i,k,L);
        p->set_coord(init.get_centroids()[i]);
        myItems.push_back(p);
    }

    vector<item*> myQuery; //vector storing all the items of the dataset (vectors)
    for (int q = 0; q < args.get_num_items(); q++) {
        item* p = new item(q,k,L);
        p->set_coord(args.get_data()[q]);
        myQuery.push_back(p);
    }

    item* m_range = new item[args.get_num_items()*L];
    int count_range=0;


    /*PREPROCESSING*/

    if(metric=="euclidean") {  //we are going to use the euclidean LSH


        typedef unordered_set<item, euclHasher, euclComparator> hashtable;

        vector<hashtable*> myTables;
        vector<item*> *all_queries = new vector<item*>[L];
        int y = 0;
        /*Parakato ginete i dimiourgia ton hashtable*/

        for (int l = 0; l < L; l++) {
            hashtable *H=new hashtable;

            y = 0;
            for (int j = 0; j < myItems.size(); j++) {

                if (y == 0) {
                    myItems[j]->set_V(*myItems[j]);
                    myItems[j]->set_t();

                    myItems[j]->the_rand_nums();
                    if (y < myQuery.size()) {

                        //apothikeuoyme ta V kai t kai gia ta queries
                        myQuery[y]->set_V1(myItems[j]->getV());
                        myQuery[y]->set_t1(myItems[j]->gett());
                        myQuery[y]->the_rand_nums();

                    }

                } else {
                    myItems[j]->set_V1(myItems[j - 1]->getV());
                    myItems[j]->set_t1(myItems[j - 1]->gett());
                    myItems[j]->the_rand_nums();


                }

                myItems[j]->TableSize = n / 2;


                H->insert(*myItems[j]);

                y++;
            }
            //gia ola ta queries
            myQuery[0]->TableSize=n / 2;
            for (y = 1; y < myQuery.size(); y++) {
                myQuery[y]->set_V1(myQuery[y - 1]->getV());
                myQuery[y]->set_t1(myQuery[y - 1]->gett());
                myQuery[y]->TableSize = n / 2;
                myQuery[y]->the_rand_nums();

            }
            myTables.push_back(H);
            all_queries[l]=myQuery;
        }



        /*END OF PREPROCESSING*/
        /* RANGE SEARCH*/

        //for range search
        bool assign_finished = false;
        double num=R/args.get_clusters(); //range/ball

        if(num>args.get_num_items()) {
            cout<<"error R/clusters: "<<num<<endl;
            return m_range;
        }


        while(assign_finished==false) {

            int keep_last = count_range;

            int points_assigned_per_iteration=0;

            for (int q = 0; q < num; q++) {

                //set the g to check buckets
                string tq = myQuery[q]->get_g();

                item b(-5, 0, 0);

                bool is_empty = true;


                for (int l = 0; l < myTables.size(); l++) {


                    unsigned long bucket = myTables[l]->bucket(*all_queries[l][q]);


                    int count_items = 0;  //to implement the "trick" if we have checked lots of items for finding the NN
                    double dist1;

                    for (auto p = (myTables[l]->begin)(bucket); p != (myTables[l]->end)(bucket); ++p) {
                        is_empty = false;

                        if (q>=args.get_num_items()-1){continue;}


                        dist1 = eucl_dist(*p, *myQuery[q]);


                        if (double_equals(R,0.0)==false) {
                            if (dist1 < c * R) {
                                item z = *myQuery[q];
                                if (myQuery[q]->is_assigned() == false) {

                                    item z1 = *p;

                                    points_assigned_per_iteration++;
                                    myQuery[q]->cluster_assign(z1.get_idi(),dist1);



                                    m_range[count_range] = *myQuery[q];

                                    count_range++;
                                }
                            }
                        }


                        count_items++;

                    }


                }


            }
            for(int i=keep_last;i<count_range;i++ ) {
                double min1 = m_range[i].get_clust_dist();
                int pos=m_range[i].get_cluster_ball();
                if(m_range[i].is_changed()==false) {
                    for (int j = i + 1; j < count_range; j++) {

                        if (m_range[j].is_equal(m_range[i])) {
                            if (m_range[j].get_clust_dist() < min1) {
                                min1 = m_range[j].get_clust_dist();
                                pos = m_range[j].get_cluster_ball();
                            }
                        }
                    }
                    for (int j = i + 1; j < count_range; j++) {

                        if (m_range[j].is_equal(m_range[i]) && m_range[j].is_changed()==false) {
                            m_range[j].change();
                            m_range[i].change();

                            m_range[j].cluster_assign(pos, min1);
                            m_range[i].cluster_assign(pos, min1);
                        }
                    }


                }


            }

            if(count_range>=args.get_num_items() ) assign_finished=true;
            else if(points_assigned_per_iteration/num<0.85 && count_range>0.7*args.get_num_items())assign_finished=true;
            else{
                if(2 > init.get_max()) R = R+2/init.get_max();
                else R = R+1;

                num=R/args.get_clusters();
                if(num>args.get_num_items() ||num > init.get_max())break;
            }


        }



        for(int i=0; i<myQuery.size();i++){
            double min=99999;
            if(myQuery[i]->is_assigned() == false){
                double temp_dist;
                int num_center;
                for(int j =0 ; j<args.get_clusters(); j++){
                    temp_dist=eucl_dist(*myQuery[i],*myItems[j]);
                    if(temp_dist<min){
                        min=temp_dist;
                        num_center = j;
                    }
                }
                myQuery[i]->cluster_assign(num_center,min);

                m_range[count_range] = *myQuery[i];

                count_range++;
            }
        }


        /*
        for(int i=0; i<myQuery.size();i++){
            myQuery[i]->freeE();
            myQuery[i]->freeRand();
        }
        for(int i=0; i<myItems.size();i++){
            myItems[i]->freeE();
        }


        for(int i=0; i<myTables.size();i++){
            delete myTables[i];
        }*/
    }

    if(metric=="cosine"){ //we are going to use cosine LSH


        typedef unordered_set<item, cosHasher, cosComparator> hashtable;

        vector<hashtable*> myTables;
        vector<item*> *all_queries = new vector<item*>[L];
        int y = 0;
        /*Parakato ginete i dimiourgia ton hashtable*/

        for (int l = 0; l < L; l++) {
            hashtable *H=new hashtable;

            y = 0;
            for (int j = 0; j < myItems.size(); j++) {

                if (y == 0) {
                    myItems[j]->set_r(*myItems[j]);
                    if (y < myQuery.size()) {

                        myQuery[y]->set_r1(myItems[j]->getr());
                    }

                } else {
                    myItems[j]->set_r1(myItems[j - 1]->getr());

                }

                myItems[j]->TableSize = n / 2;


                H->insert(*myItems[j]);

                y++;
            }
            //gia ola ta queries
            myQuery[0]->TableSize=n / 2;
            for (y = 1; y < myQuery.size(); y++) {
                myQuery[y]->set_r1(myQuery[y - 1]->getr());
                myQuery[y]->TableSize = n / 2;

            }
            myTables.push_back(H);
            all_queries[l]=myQuery;
        }

        /*END OF PREPROCESSING*/

        /* RANGE SEARCH*/
        //for range search



        //for range search
        bool assign_finished = false;
        double num=R; //range/ball

        if(num>args.get_num_items()) {
            cout<<"error R/clusters: "<<num<<endl;
            return m_range;
        }
        while(assign_finished==false) {
            int keep_last = count_range;


            int points_assigned_per_iteration = 0;

            for (int q = 0; q < myQuery.size(); q++) {


                item b(-5, 0, 0);

                bool is_empty = true;


                for (int l = 0; l < myTables.size()-1; l++) {


                    unsigned long bucket = myTables[l]->bucket(*all_queries[l][q]);


                    int count_items = 0;  //to implement the "trick" if we have checked lots of items for finding the NN
                    double dist1;
                    double dist2;
                    for (auto p = (myTables[l]->begin)(bucket); p != (myTables[l]->end)(bucket); ++p) {

                        is_empty = false;
                        if (q>=args.get_num_items()-1){continue;}

                        dist1 = cos_dist(*p, *myQuery[q]);
                        //Range search below

                        if (double_equals(R,0.0)==false) {
                            if (dist1 < c * R) {
                                item z = *myQuery[q];
                                if (myQuery[q]->is_assigned() == false) {

                                    item z1 = *p;

                                    points_assigned_per_iteration++;
                                    myQuery[q]->cluster_assign(z1.get_idi(),dist1);



                                    m_range[count_range] = *myQuery[q];

                                    count_range++;
                                }
                            }
                        }

                        count_items++;
                    }


                }


            }

            for(int i=keep_last ;i<count_range;i++ ) {
                double min1 = m_range[i].get_clust_dist();
                int pos=m_range[i].get_cluster_ball();
                if(m_range[i].is_changed()==false) {
                    for (int j = i + 1; j < count_range; j++) {

                        if (m_range[j].is_equal(m_range[i])) {
                            if (m_range[j].get_clust_dist()< min1) {
                                min1 = m_range[j].get_clust_dist();
                                pos = m_range[j].get_cluster_ball();
                            }
                        }
                    }
                    for (int j = i + 1; j < count_range; j++) {

                        if (m_range[j].is_equal(m_range[i]) && m_range[j].is_changed()==false) {
                            m_range[j].change();
                            m_range[i].change();

                            m_range[j].cluster_assign(pos, min1);
                            m_range[i].cluster_assign(pos, min1);
                        }
                    }


                }


            }

            if(count_range>=args.get_num_items() ) assign_finished=true;
            else if(points_assigned_per_iteration/num<0.85 && count_range > 0.7*args.get_num_items()) assign_finished=true;
            else{
                if(2 > init.get_max()) R = R+2/init.get_max();
                else R = R+1;

                num=R/args.get_clusters();
                if(num>args.get_num_items() || num,init.get_max())break;
            }

        }

        for(int i=0; i<myQuery.size();i++){
            double min=99999;
            if(myQuery[i]->is_assigned() == false){
                double temp_dist;
                int num_center;
                for(int j =0 ; j<args.get_clusters(); j++){
                    temp_dist=cos_dist(*myQuery[i],*myItems[j]);
                    if(temp_dist<min){
                        min=temp_dist;
                        num_center = j;
                    }
                }
                myQuery[i]->cluster_assign(num_center,min);

                m_range[count_range] = *myQuery[i];

                count_range++;
            }
        }


        /*     for(int i=0; i<myQuery.size();i++){
                 myQuery[i]->freeC();
             }
             for(int i=0; i<myItems.size();i++){
                 myItems[i]->freeC();
             }


             for(int i=0; i<myTables.size();i++){
                 delete myTables[i];
             }
             */

    }




    /*for(int i=0; i<myItems.size();i++){
        delete myItems[i];
    }


    for(int i=0; i<myQuery.size();i++){
        delete myQuery[i];
    }
*/
    fflush(stdout);

    for (int i=0; i<count_range;i++){
        if(m_range[i].get_cluster_ball()<args.get_clusters()) {
            clusters[m_range[i].get_cluster_ball()].cluster_data[clusters[m_range[i].get_cluster_ball()].counter] = m_range[i].get_point();
            clusters[m_range[i].get_cluster_ball()].cluster_data_id.push_back(m_range[i].get_idi());

            clusters[m_range[i].get_cluster_ball()].counter++;
        }


    }


    if(old_clustering!=NULL) {
        int count_d=0;
        for (int i = 0; i < old_clustering->get_size(); i++) {

            for (int j=0; j<count_range-1;j++) {


                if(m_range[j].is_equal(old_clustering[i]) && m_range[j].get_cluster_ball()!=old_clustering[i].get_cluster_ball()){
                    count_d++;

                    break;

                }

            }

            if(count_d>190) {
                done = false;
                break;
            }
        }

    }



    return m_range;
}

int e = 1;

item* assignment::cube( argClass args,  initialization init, assignment assign,item* old_clustering) {

    if(old_clustering!=NULL) done=true;

    ifstream ifs; //dataset stream
    ifstream query_file; //query stream
    ofstream output; //output stream

    int M=150; //max number of points to be checked
    int probes=1; //max number of vertices to be checked

    //get parameters

    int n = args.get_num_items();
    string metric = args.get_metric();
    int L = args.get_L();
    int k = args.get_hash_func_num();
    int c=1;
    double R=init.get_min()/2; //Radius given

    double d2 =3;



    vector<item*> myItems; //vector storing all the items of the dataset (vectors)
    for (int i = 0; i < args.get_clusters(); i++) {
        item* p = new item(i,k,L);
        p->set_coord(init.get_centroids()[i]);
        myItems.push_back(p);
    }

    vector<item*> myQuery; //vector storing all the items of the dataset (vectors)
    for (int q = 0; q < args.get_num_items(); q++) {
        item* p = new item(q,k,L);
        p->set_coord(args.get_data()[q]);
        myQuery.push_back(p);
    }

    item* m_range = new item[args.get_num_items()*L];
    int count_range=0;

    if(metric=="euclidean") {  //we are going to use the euclidean hypercube

        int y = 0;

        hypercube hyper_eucl[myItems.size()];

        //vector<double>* f=new vector<double>[myItems.size()];

        for (int j = 0; j < myItems.size(); j++) {
            //  hyper_eucl[j].set_size(myItems.size());
            //hyper_eucl[j].alloc(myItems.size());

            if (y == 0) {

                myItems[j]->set_V(*myItems[j]);
                myItems[j]->set_t();
                myItems[j]->the_rand_nums();
                if (y < myQuery.size()) {

                    //apothikeuoyme ta V kai t kai gia ta queries
                    myQuery[y]->set_V1(myItems[j]->getV());
                    myQuery[y]->set_t1(myItems[j]->gett());
                    myQuery[y]->the_rand_nums();

                }


            } else {

                myItems[j]->set_V1(myItems[j - 1]->getV());
                myItems[j]->set_t1(myItems[j - 1]->gett());
                myItems[j]->the_rand_nums();

            }

            myItems[j]->TableSize = n / 2;

            y++;
        }

        //gia ola ta queries
        myQuery[0]->TableSize = n / 2;
        for (y = 1; y < myQuery.size(); y++) {
            myQuery[y]->set_V1(myQuery[y - 1]->getV());
            myQuery[y]->set_t1(myQuery[y - 1]->gett());
            myQuery[y]->TableSize = n / 2;
            myQuery[y]->the_rand_nums();

        }

        // if (std::equal(v1.begin(), v1.begin() + n, v2.begin())
        vector<double> *FV = new vector<double>[myItems.size()];

        for (int j = 0; j < myItems.size(); j++) {

            calculate_f(FV[j], myItems[j], d2);

            int vertex = get_vertex(FV[j], d2);
            if(vertex>=myItems.size()){
                continue;
            }

            hyper_eucl[vertex].insert_vertex(FV[j], *myItems[j]);

        }

        delete[] FV;



        bool assign_finished = false;
        double num=R/args.get_clusters(); //range/ball

        if(num>args.get_num_items()) {
            cout<<"error R/clusters: "<<num<<endl;
            return m_range;
        }

        while(assign_finished==false) {

            int keep_last = count_range;

            int points_assigned_per_iteration = 0;

            for (int q = 0; q < myQuery.size()-1; q++) {

                vector<double> FV;
                calculate_f(FV, myQuery[q], d2);
                int vertex = get_vertex(FV, d2);
                if(vertex>=myItems.size()){
                    continue;
                }


                int count_vertices = 0;
                int points_checked = 0;
                double dist = 99999;




                while (count_vertices < probes && points_checked < M) {

                    double dist1 = 0;
                    for (int i = 0; i < hyper_eucl[vertex].get_f().size(); i++) {

                        item v = hyper_eucl[vertex].get_item()[i];
                        dist1 = eucl_dist(v, *myQuery[q]);
                        //dist1 = ham_dist(v.get_point(), myQuery[q]->get_point());

                        if (double_equals(R,0.0)==false) {
                            if ((dist1 < e * R)) {

                                item z = *myQuery[q];
                                if (myQuery[q]->is_assigned() == false) {

                                    item z1 = v;

                                    points_assigned_per_iteration++;
                                    myQuery[q]->cluster_assign(z1.get_idi(), dist1);


                                    m_range[count_range] = *myQuery[q];

                                    count_range++;
                                }


                            }
                        }


                        points_checked++;
                        if (points_checked > M) {
                            break;
                        }
                    }

                    int min_dist_ham = 99999;

                    for (int i = 0; i < myItems.size(); i++) {

                        if (hyper_eucl[i].has_points() > 0) {
                            item v = hyper_eucl[i].get_item()[0];
                            dist1 = ham_dist(v.get_point(), myQuery[q]->get_point());

                            if (dist1 < min_dist_ham){
                                min_dist_ham = dist1;
                                vertex = i;
                            }
                        }
                    }
                    count_vertices++;


                }


            }

            for(int i=keep_last;i<count_range;i++ ) {
                double min1 = m_range[i].get_clust_dist();
                int pos=m_range[i].get_cluster_ball();

                if(m_range[i].is_changed()==false) {
                    for (int j = i + 1; j < count_range-1; j++) {

                        if (m_range[j].is_equal(m_range[i])) {
                            if (m_range[j].get_clust_dist() < min1) {
                                min1 = m_range[j].get_clust_dist();
                                pos = m_range[j].get_cluster_ball();
                            }
                        }
                    }
                    for (int j = i + 1; j < count_range-1; j++) {

                        if (m_range[j].is_equal(m_range[i]) && m_range[j].is_changed()==false) {
                            m_range[j].change();
                            m_range[i].change();

                            m_range[j].cluster_assign(pos, min1);
                            m_range[i].cluster_assign(pos, min1);
                        }
                    }


                }


            }

            if(count_range>=args.get_num_items() ) assign_finished=true;
            else if((points_assigned_per_iteration/num<0.85) && (count_range>0.7*args.get_num_items())) assign_finished=true;
            else{
                if((2 > init.get_max())) R = R+2/init.get_max();
                else R = R+1;

                num=R/args.get_clusters();
                if(num>args.get_num_items() || (num>init.get_max()))break;
            }



            /*

            for(int i=0; i<myQuery.size();i++){
                myQuery[i]->freeE();
                myQuery[i]->freeRand();
            }
            for(int i=0; i<myItems.size();i++){
                myItems[i]->freeE();
            }*/

        }


        for(int i=0; i<myQuery.size();i++){
            double min=99999;
            if(myQuery[i]->is_assigned() == false){
                double temp_dist;
                int num_center;
                for(int j =0 ; j<args.get_clusters(); j++){
                    temp_dist=eucl_dist(*myQuery[i],*myItems[j]);
                    if((temp_dist<min)){
                        min=temp_dist;
                        num_center = j;
                    }
                }
                myQuery[i]->cluster_assign(num_center,min);

                m_range[count_range] = *myQuery[i];

                count_range++;
            }
        }

    }


    if(metric=="cosine") {  //we are going to use the cosine hypercube
        int y = 0;

        hypercube hyper_cos[myItems.size()];


        y = 0;
        for (int j = 0; j < myItems.size(); j++) {

            if (y == 0) {
                myItems[j]->set_r(*myItems[j]);
                if (y < myQuery.size()) {

                    myQuery[y]->set_r1(myItems[j]->getr());
                }

            } else {
                myItems[j]->set_r1(myItems[j - 1]->getr());

            }

            myItems[j]->TableSize = n / 2;

            y++;
        }



        //gia ola ta queries
        myQuery[0]->TableSize = n / 2;
        for (y = 1; y < myQuery.size(); y++) {
            myQuery[y]->set_r1(myQuery[y - 1]->getr());
            myQuery[y]->TableSize = n / 2;

        }

        vector<double> *FV = new vector<double>[myItems.size()];

        for (int j = 0; j < myItems.size(); j++) {

            calculate_c(FV[j], myItems[j], d2);
            int vertex = get_vertex(FV[j], d2);

            if(vertex>=myItems.size()){
                continue;
            }

            hyper_cos[vertex].insert_vertex(FV[j], *myItems[j]);
        }

        delete[] FV;

        /*END OF PREPROCESSING*/

        /*RANGE SEARCH*/

        //for range search


        bool assign_finished = false;
        double num=R/args.get_clusters(); //range/ball

        if(num>args.get_num_items()) {
            cout<<"error R/clusters: "<<num<<endl;
            return m_range;
        }

        while(assign_finished==false) {

            int keep_last = count_range;

            int points_assigned_per_iteration = 0;

            for (int q = 0; q < myQuery.size()-1; q++) {

                vector<double> FV;
                calculate_c(FV, myQuery[q], d2);
                int vertex = get_vertex(FV, d2);
                if(vertex>=myItems.size()){
                    continue;
                }



                int count_vertices = 0;
                int points_checked = 0;
                double dist = 99999;
                int keep_vertices[probes];
                int count_my_kept=0;
                double dist1 = 0;

                int min_dist_ham = 99999;

                if(probes>1){
                    for (int i = 0; i < myItems.size(); i++) {
                        if (hyper_cos[i].has_points() > 0) {

                            item v = hyper_cos[i].get_item()[0];
                            dist1 = ham_dist(v.get_point(), myQuery[q]->get_point());

                            if ((dist1 < min_dist_ham)) {
                                min_dist_ham = dist1;
                                keep_vertices[count_my_kept]=i;
                                count_my_kept++;
                                if(count_my_kept>=probes) count_my_kept=0;   //care
                            }
                        }
                    }
                }
                



                while (count_vertices < probes && points_checked < M) {


                    for (int i = 0; i < hyper_cos[vertex].get_f().size(); i++) {

                        item v = hyper_cos[vertex].get_item()[i];
                 
                        dist1 = cos_dist(v, *myQuery[q]);
                 

                        if (double_equals(R,0.0)==false) {
                            if ((dist1 <e * R)) {

                                item z = *myQuery[q];
                                if (myQuery[q]->is_assigned() == false) {

                                    item z1 = v;

                                    points_assigned_per_iteration++;
                                    myQuery[q]->cluster_assign(z1.get_idi(), dist1);


                                    m_range[count_range] = *myQuery[q];

                                    count_range++;
                                }


                            }
                        }


                        points_checked++;
                        if (points_checked > M || count_vertices>=probes) {
                            break;
                        }
                    }



                    vertex = keep_vertices[count_vertices];
                    count_vertices++;


                }


            }

            for(int i=keep_last;i<count_range;i++ ) {
                double min1 = m_range[i].get_clust_dist();
                int pos=m_range[i].get_cluster_ball();

                if(m_range[i].is_changed()==false) {
                    for (int j = i + 1; j < count_range-1; j++) {

                        if (m_range[j].is_equal(m_range[i])) {
                            if (m_range[j].get_clust_dist() < min1) {
                                min1 = m_range[j].get_clust_dist();
                                pos = m_range[j].get_cluster_ball();
                            }
                        }
                    }
                    for (int j = i + 1; j < count_range-1; j++) {

                        if (m_range[j].is_equal(m_range[i]) && m_range[j].is_changed()==false) {
                            m_range[j].change();
                            m_range[i].change();

                            m_range[j].cluster_assign(pos, min1);
                            m_range[i].cluster_assign(pos, min1);
                        }
                    }


                }


            }

            if(count_range>=args.get_num_items() ) assign_finished=true;
            else if((points_assigned_per_iteration/num<0.85) && (count_range>0.7*args.get_num_items())) assign_finished=true;
            else{

                if((2 > init.get_max())) R = R+2/init.get_max();
                else R = R+1;

                num=R/args.get_clusters();
                if(num>args.get_num_items() || (num>init.get_max()))break;
            }

            /*
            for(int i=0; i<myQuery.size();i++){
                myQuery[i]->freeC();
            }
            for(int i=0; i<myItems.size();i++){
                myItems[i]->freeC();
            }
    */
        }

        for(int i=0; i<myQuery.size();i++){
            double min=99999;
            if(myQuery[i]->is_assigned() == false){
                double temp_dist;
                int num_center;
                for(int j =0 ; j<args.get_clusters(); j++){
                    temp_dist=eucl_dist(*myQuery[i],*myItems[j]);
                    if((temp_dist<min)){
                        min=temp_dist;
                        num_center = j;
                    }
                }
                myQuery[i]->cluster_assign(num_center,min);

                m_range[count_range] = *myQuery[i];

                count_range++;
            }
        }

    }

/*
    for(int i=0; i<myItems.size();i++){
        delete myItems[i];
    }


    for(int i=0; i<myQuery.size();i++){
        delete myQuery[i];
    }
*/

    for (int i=0; i<count_range;i++){
        if(m_range[i].get_cluster_ball()<args.get_clusters()) {
            clusters[m_range[i].get_cluster_ball()].cluster_data[clusters[m_range[i].get_cluster_ball()].counter] = m_range[i].get_point();
            clusters[m_range[i].get_cluster_ball()].cluster_data_id.push_back(m_range[i].get_idi());

            clusters[m_range[i].get_cluster_ball()].counter++;
        }


    }


    if(old_clustering!=NULL) {
        int count_d=0;
        for (int i = 0; i < old_clustering->get_size(); i++) {

            for (int j=0; j<count_range-1;j++) {


                if(m_range[j].is_equal(old_clustering[i]) && m_range[j].get_cluster_ball()!=old_clustering[i].get_cluster_ball()){
                    count_d++;

                    break;

                }

            }

            if(count_d>190) {
                done = false;
                break;
            }
        }

    }

    return m_range;
}

