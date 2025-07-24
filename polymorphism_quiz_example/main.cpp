#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Question {
    public:
    Question(string questionText, int pointVal){
        this->questionText = questionText;
        this->pointVal = pointVal;
        isCorrect = false;
    }

    virtual void askQuestion() = 0;

    int getPointsScored() const {
        return pointVal * isCorrect;
    }

    int getPointValue() const {
        return pointVal;
    }

    protected:
    bool isCorrect;
    string questionText;
    int pointVal;
};

class MathQuestion : public Question {
    public:
    MathQuestion(string questionText, int pointVal, double correctAnswer) : Question(questionText, pointVal) {
        this->correctAnswer = correctAnswer;
    }

    void askQuestion() {
        cout << questionText << endl;
        double userAnswer;
        cin >> userAnswer;
        if(abs(userAnswer - correctAnswer) < 0.001){
            isCorrect = true;
        }
    }

    private:
    double correctAnswer;
};

class TrueFalseQuestion : public Question {
    public:
    TrueFalseQuestion(string questionText, int pointVal, bool correctAnswer) : Question(questionText, pointVal) {
        this->correctAnswer = correctAnswer;
    }

    void askQuestion(){
        cout << questionText << endl;
        cout << "Answer T for True or F for false:" << endl;
        char userInput;
        bool userAnswer = false;
        cin >> userInput;

        if(userInput == 'T' || userInput == 't'){
            userAnswer = true;
        }

        if(userAnswer == correctAnswer){
            isCorrect = true;
        }
    }

    private:
    bool correctAnswer;
};

int main(){
    vector<Question*> quiz;

    MathQuestion question1("What is 2 + 2?", 10, 4.0);
    MathQuestion question2("What is 3 - 2?", 10, 1.0);
    TrueFalseQuestion question3("A Coldplay concert is a great place to take your mistress.", 10, false);

    quiz.push_back(&question1);
    quiz.push_back(&question2);
    quiz.push_back(&question3);

    int score = 0;
    int total = 0;
    for(int i = 0; i < quiz.size(); i++){
        quiz.at(i)->askQuestion();
        score += quiz.at(i)->getPointsScored();
        total += quiz.at(i)->getPointValue();
    }

    cout << "You scored a " << ((double)score/total) * 100.0 << "." << endl;


    return 0;
}