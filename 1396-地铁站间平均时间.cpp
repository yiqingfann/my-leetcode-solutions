// https://leetcode.com/problems/design-underground-system/

class UndergroundSystem {
  public:
    // id -> (a, ta)
    // a -> b -> (tot, cnt)
    typedef pair<string, int> psi;
    typedef pair<int, int> pii;
    unordered_map<int, psi> checkin;
    unordered_map<string, unordered_map<string, pii>> record;

    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [a, ta] = checkin[id];
        string b = stationName;
        int tb = t;
        record[a][b].first += tb - ta;
        record[a][b].second++;
        checkin.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        string a = startStation, b = endStation;
        return (double)record[a][b].first / record[a][b].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */