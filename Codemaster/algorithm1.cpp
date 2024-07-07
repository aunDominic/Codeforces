#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <bitset>
#include <numeric>
#include <string.h>
#include <random>
#include <cassert>
#include <iomanip>
#include <ios>
#include <map>
#include <climits>
using namespace std;

const int N = 100;

bool visited[N][N] = {false};
vector<string> garden = {"sbixvtcvenoteesaqbcbuynyyzpuyxmohniluvqjvjazuaeuusyijqyqvzyyrhvwfmebetsbovuqsmpneidkesszqbntnagvklyi", "acqlymrsnozaiuhaxakarrhitcckrvphaetztjafnuqvdxflzqdkydzecqsmzwcjgdpverhizzbpzjousortousaedqhzwpsswsz", "zhgbunmtraymeghqxmqbkgwrynmlvpeaftkwcqivtybemnxqfxezktsywhwucmhuzffqqsoaxlmrgunljapxxmsrgplgvpeucktt", "bbovyqkkodvqhjuxzpzjnzknxcszuuevrmsqyquwsbnrbhitrqagazfwayfvmfopmxkowobadywwjmofeitayfqmzxbikgslsuai", "xxvksdmeplfuhjcffpvfzcnhvveklmtkydawbdakbtgfwjksomxhdizuktuvltfpwnlkimziuzegmmulxkghjfrfkpneuriqbkpd", "hrqgwbcajhasijnwqhgpjjwmiwqlntpwcqcgfmrmfxrlnbnanpclfyfslzxwfksvpbsbwdllpblnnycvgohxqggvyzorgfivbqyg", "acfplhphynvxpwrvedtlgbfuniugazpfykaohxlfztvyjqntmxkaegipspdfjenfxzeljteyydkynzekrmzkpixgpzyjngscdxjp", "qmlvlqrzjhdsotivkrerjwqphvgdemuzuoyzhsxuqnnhihhqjnbtklyguwcbzwlexrafecnsxemcngpqiogvdsunttbkougdmlmi", "bzxhqzvbtyjkvavlrtwdkebqvlowbawoaolyoqupjrwnqqavbqkejijolfmyrjugqkuzezortyxoumjlbjpmqvgwpybxnvoeropb", "hxrxuynivuvgszomlwcwidjtpxwrjvelzwwcxtomdjzcbvhqiofbkwftlzwvmwjzuuwizpucgsmhjbwexxmhpfphpmwlzrixlbgb", "ptickdsmjwlswuzljithvbqlcfcikpebijadncnhjszalclplcuerprtjphksgaedgseopslmelbecxhzcblaserwbhcygvicbbv", "ylrjccihcvqdjsejukrqmvigjyrfppnrahmnahvqzigscqtfnikmkcnavnthqiglzrogrdymtmhxvveirtqsbdrsnmwokbfwryex", "kpbgqjfrrxniyazjbmzivkyvyherqvvqdfqwfrggprqkemgblbiwqbdfmiywybjnanongahrrutorxttbvrudmhbkhioozziaqvb", "mxxofdulrtewagebkjkvpmxbiwyvhhnjxdrzsasxwrzcoskbslpnxkthgytovufvfdptapwxvzlfnvrfjufcetcvxdtcpfsapjaj", "vbeaslfoaozqottazlilkqxyrtklrnzmfaqwdcakffixbtczsjzpvxgmuzdrivukqsknfohwfdgqsglmjzqgpplakprjujozpywx", "wxddcxynrltbofzpbhpmizaxjjppzlsujnhmlwhkcuwxefozfwpegwqxpgvyrihtnkwaeuairqwlnkjikciyhcwojrakeicsqcae", "ewlyxgdviyautlbajvdomgeanhuteofjbjqklvswrqcjyuianlcevqwwglpwzjnbwmfcqktvncptooivdjuzfmmimnuljghetelu", "dxwbcpbzgdoqzemicqnnastrhqkydkwdahaqhiavrvcgqvnjvxmevjpspyciykriykvofnnbeuvlmzbhyjgpdjuxvmlappgxqzzw", "mihisxqmeqpaciycnhjfnjoyoyqpamjptjpokbyzxijoyljnlsmrkghempsbradrjdyfpbhnenpuyrpgkgwqdoezxqvcuuiricer", "izybcdcvdvkdqlnkuaoewssfaniglqyleinfqeyeuzrjglejbnscuzqjagxflemqtbipeowsmjbiriptpkwmaltavafkwbqucpbi"};
// vector<string> garden = {"abbca", "aacaa", "aacca", "zzzzz", "gamer"};
int n = garden.size();
int m = garden[0].size();
void ff (int x, int y, char c){
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || garden[x][y] != c){
        return;
    }
    visited[x][y] = true;

    ff(x+1, y, c);
    ff(x-1, y, c);
    ff(x, y+1, c);
    ff(x, y-1, c);
}

int main () {
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!visited[i][j]){
                ff(i,j, garden[i][j]);
                ans++;
            }
        }
    }
    cout << ans;


}