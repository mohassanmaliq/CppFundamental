#include &lt;iostream&gt;
#include &lt;fstream&gt;
using namespace std;
ofstream out;
ifstream imp;
int main()
{
cout &lt;&lt; &quot;.......................................&quot; &lt;&lt; endl;
int a;
int b;
cout &lt;&lt; &quot;enter two number diff by space&quot; &lt;&lt; endl;
cin &gt;&gt; a &gt;&gt; b;
int sum = a + b;
cout &lt;&lt; &quot;sum is :&quot; &lt;&lt; sum &lt;&lt; endl;
out.open(&quot;data.txt&quot;);
out &lt;&lt; sum &lt;&lt; endl;
out.close();
cout &lt;&lt; &quot;saved&quot; &lt;&lt; endl;
return 0;
}