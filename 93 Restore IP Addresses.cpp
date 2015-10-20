static List<String> restoreIpAddresses(String s)
{
    List<String> ans = new ArrayList<String>();
    int len = s.length();
    for (int i = 1; i <=3; ++i)   // first cut
    {
        if (len-i > 9) continue;
        for (int j = i+1; j<=i+3; ++j)   //second cut
        {
            if (len-j > 6) continue;
            for (int k = j+1; k<=j+3 && k<len; ++k)   // third cut
            {
                int a,b,c,d;                // the four int's seperated by "."
                a = Integer.parseInt(s.substring(0,i));
                b = Integer.parseInt(s.substring(i,j)); // notice that "01" can be parsed into 1. Need to deal with that later.
                c = Integer.parseInt(s.substring(j,k));
                d = Integer.parseInt(s.substring(k));
                if (a>255 || b>255 || c>255 || d>255) continue;
                String ip = a+"."+b+"."+c+"."+d;
                if (ip.length()<len+3) continue;  // this is to reject those int's parsed from "01" or "00"-like substrings
                ans.add(ip);
            }
        }
    }
    return ans;
}


public List<String> restoreIpAddresses(String s)
{
    List<String> solutions = new ArrayList<String>();
    restoreIp(s, solutions, 0, "", 0);
    return solutions;
}

private void restoreIp(String ip, List<String> solutions, int idx, String restored, int count)
{
    if (count > 4) return;
    if (count == 4 && idx == ip.length()) solutions.add(restored);

    for (int i=1; i<4; i++)
    {
        if (idx+i > ip.length()) break;
        String s = ip.substring(idx,idx+i);
        if ((s.startsWith("0") && s.length()>1) || (i==3 && Integer.parseInt(s) >= 256)) continue;
        restoreIp(ip, solutions, idx+i, restored+s+(count==3?"" : "."), count+1);
    }
}


