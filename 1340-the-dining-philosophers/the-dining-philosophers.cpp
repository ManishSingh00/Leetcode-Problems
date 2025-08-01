class DiningPhilosophers {
private:
    mutex m[5];
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        int left = philosopher;
        int right = (philosopher+1) % 5;

        if(philosopher%2==0){
            m[right].lock();
            m[left].lock();
            pickRightFork();
            pickLeftFork();
        }
        else{
            m[left].lock();
            m[right].lock();
            pickLeftFork();
            pickRightFork();
        }

        eat();
        putLeftFork();
        putRightFork();

        m[left].unlock();
        m[right].unlock();

		
    }
};