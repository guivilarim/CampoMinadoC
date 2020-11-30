#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED

struct ranking
{
    int sec;
    time_t start, end;
    double dif;

}timer;


void tempo();
void addRanking();
void printRanking();

#endif // RANKING_H_INCLUDED
