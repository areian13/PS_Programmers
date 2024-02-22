#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Song
{
    int idx;
    int play;

    friend bool operator>(const Song& a, const Song& b)
    {
        if (a.play != b.play)
            return a.play > b.play;
        return a.idx < b.idx;
    }
};

struct Genre
{
    vector<Song> songs;
    int sum = 0;

    void Organize()
    {
        for (Song song : songs)
            sum += song.play;
        sort(songs.begin(), songs.end(), greater<Song>());
    }
    friend bool operator>(const Genre& a, const Genre& b)
    {
        return a.sum > b.sum;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays)
{
    unordered_map<string, Genre> list;

    int n = genres.size();
    for (int i = 0; i < n; i++)
        list[genres[i]].songs.push_back({ i,plays[i] });

    vector<Genre> temp;
    for (auto& genre : list)
    {
        genre.second.Organize();
        temp.push_back(genre.second);
    }
    sort(temp.begin(), temp.end(), greater<Genre>());

    vector<int> result;
    int t = temp.size();
    for (int i = 0; i < t; i++)
    {
        int k = min(2, (int)temp[i].songs.size());
        for (int j = 0; j < k; j++)
            result.push_back(temp[i].songs[j].idx);
    }
    return result;
}