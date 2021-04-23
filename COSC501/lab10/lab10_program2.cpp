// Lab 10 Program 2: Class
// Doug Branton

#include <iostream>
#include <iomanip>

using namespace std;

class Movie
{
    public:
        // create a movie object from a name and MPAA rating
        Movie(string name, string mpaa_rating);

        // get the details of the movie
        string getName();
        string getRating();
        int getUserScore(int index); //get the number of users that gave a specific score

        // set the details of the movie
        void setName(string new_name);
        void setRating(string new_mpaa_rating);
        void setUserScores(int new_user_scores[5]);

        // add a new 1-5 rating to the movie reviews
        void addRating(int user_rating);

        // get the average of the movie ratings
        double getAverage();

    private:
        string name;
        string mpaa_rating;
        int user_scores[5]; // Ordering: Terrible, Bad, OK, Good, Great


};



int main(){
    Movie interstellar("Interstellar", "PG-13"), toy_story_3("Toy Story 3", "G");
    int int_scores[5]={1,2,3,3,5}, toystory_scores[5] = {1,2,4,4,4};
    
    interstellar.setUserScores(int_scores);
    toy_story_3.setUserScores(toystory_scores);

    cout << "Movie Information" << endl;
    cout << left << setw(15) << interstellar.getName() << setw(7) << interstellar.getRating() << interstellar.getAverage() << endl;
    cout << left << setw(15) << toy_story_3.getName() << setw(7) << toy_story_3.getRating() << toy_story_3.getAverage() << endl;

    //Adding a rating
    //cout << interstellar.getUserScore(5) << endl;
    //interstellar.addRating(5);
    //cout << interstellar.getUserScore(5) << endl;


}

Movie::Movie(string movie_name, string movie_mpaa_rating){
    name = movie_name;
    mpaa_rating = movie_mpaa_rating;

    for (int i=0; i < 5; i++){
        user_scores[i] = 0;
    }
}

string Movie::getName(){
    return name;
}

string Movie::getRating(){
    return mpaa_rating;
}

int Movie::getUserScore(int index){
    if ((index <= 5) && (index >= 1)){
    return user_scores[index-1];
    }
    else{
        cout << "Invalid movie rating. The rating must be an integer between 1 and 5." << endl;
        return 0;
    }

}

void Movie::setName(string new_name){
    name = new_name;
    }

void Movie::setRating(string new_mpaa_rating){
    mpaa_rating = new_mpaa_rating;
}

void Movie::setUserScores(int new_user_scores[5]){
    for (int i=0; i < 5; i++){
        user_scores[i] = new_user_scores[i];
    }
}

void Movie::addRating(int user_rating){
    if ((user_rating <= 5) && (user_rating >= 1)){
    user_scores[user_rating-1]++; //increment at the appropriate list index
    }
    else{
        cout << "Invalid movie rating. The rating must be an integer between 1 and 5." << endl;
    }
}

double Movie::getAverage(){
    // 1 * num 1s + 2 * num 2s + ... / num reviews
    double avg = 0.0;
    int num = 0;
    for (int i=0; i < 5; i++){
        avg += (i+1)*user_scores[i];
        num += user_scores[i];
    }
    avg /= num;
    return avg;
}