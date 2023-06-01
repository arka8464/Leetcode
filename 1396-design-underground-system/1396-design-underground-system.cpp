class UndergroundSystem {
     unordered_map<int, pair<string, int> >checkIns;        // id : {stationName, time}
    unordered_map<string, pair<int, int> > timings;    // startStation-endStation : {sumOfTime, count}
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string s = checkIns[id].first+'-'+stationName;
        
        timings[s]={timings[s].first+(t - checkIns[id].second),timings[s].second+1};
        checkIns.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int> p = timings[startStation + '-' + endStation];
		
        return (double)p.first / p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */