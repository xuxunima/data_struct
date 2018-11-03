#include<iostream>
#include<algorithm>
using namespace std;
#define maxUser 10001
#define maxid 1000000
#define maxk 6

int fullmark[maxk];

struct userNode {
	int uid;
	int totalScore;
	int solvedProblem;
	int *scores;
	//���캯�� 
	userNode() {
		uid = maxid;
		totalScore = 0;
		solvedProblem = 0;
		scores = new int[maxk];
		for (int i = 1; i<maxk; i++) {
			scores[i] = -2;     //��ʼ��Ϊ-2�������������ֿ� 
		}
	}

	//�����ܷ�
	void getTotalScore(int k) {//����Ϊ��Ŀ������ 
		for (int i = 1; i <= k; i++) {
			if (scores[i] >0)    totalScore += scores[i];
		}
	}
	//������ȫ�������������
	void getSolvedProlem(int fullmark[], int k) {
		for (int i = 1; i <= k; i++) {
			if (scores[i] == fullmark[i])    solvedProblem++;
		}
	}

	//���ض���<�����������ȽϹ���,����sort�ıȽ�����Ҫ��const��
	bool operator<(const userNode &other) const {
		if (totalScore != other.totalScore)  return totalScore > other.totalScore;
		if (solvedProblem != other.solvedProblem)    return solvedProblem > other.solvedProblem;
		return uid<other.uid;
	}

	//�������֮��Ĳ��� 
	void print(int k) {
		printf("%05d %d", uid, totalScore);
		for (int i = 1; i <= k; i++) {
			if (scores[i] == -2)         printf(" -");       //����û���ύ������ 
			else if (scores[i] == -1)    printf(" 0");       //����������
			else                        printf(" %d", scores[i]);

		}
		printf("\n");
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("patJudge.txt", "r", stdin);
#endif

	struct userNode users[maxUser];


	int N, K, M;
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 1; i <= K; i++) {
		scanf("%d", &fullmark[i]);
	}

	int uid, proid, score_obtained;
	int listNum = 0;        //�����Ҫ����ĸ��� 
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &uid, &proid, &score_obtained);

		//ֻҪ����ͨ������ǰû���г�������Ӧ�ñ���� 
		if (score_obtained >= 0 && users[uid].uid == maxid) {
			listNum++;
			users[uid].uid = uid;
		}
		if (score_obtained > users[uid].scores[proid])
			users[uid].scores[proid] = score_obtained;
	}

	for (int i = 1; i <= N; i++) {
		users[i].getSolvedProlem(fullmark, K);
		users[i].getTotalScore(K);
	}

	sort(users + 1, users + N + 1);

	int rank = 1, lastTotal = 10000000;
	for (int i = 1; i <= listNum; i++) {
		if (users[i].totalScore != lastTotal) {
			rank = i;
			lastTotal = users[i].totalScore;
		}
		printf("%d ", rank);
		users[i].print(K);
	}

	return 0;

}