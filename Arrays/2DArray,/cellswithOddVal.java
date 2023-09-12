

class cellswithOddVal{
    public int oddCells(int m, int n, int[][] indices) {
        int row[] = new int[m];
        int col[] = new int[n];
        int ans=0;
        for(int i=0;i<indices.length;i++)
        {
            // row index
            row[indices[i][0]]++;
            //col index
            col[indices[i][1]]++;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int element = row[i]+col[j];
                if(element%2 !=0) ans++;
            }
        }
        return ans;
    }
}