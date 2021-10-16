// int max_so_far=0;
// 	     int min_ending_here=0;
// 	     int max_ending_here=0;
// 	    for(int i=0;i<n;i++){
// 	         int temp=max_ending_here;
// 	        max_ending_here=max(arr[i],max(max_ending_here*arr[i],min_ending_here*arr[i]));
// 	        min_ending_here=min(arr[i],min(temp*arr[i],min_ending_here*arr[i]));
// 	        if(max_so_far<max_ending_here)
// 	        max_so_far=max_ending_here;
// 	    }
// 	    return max_so_far;