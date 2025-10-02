#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

// Represents a major industry or landmark
struct EconomicSector {
    std::string name;
    std::string type;
    std::string description;
};

// Manages information about Jetpur
class JetpurInfoSystem {
private:
    std::unordered_map<std::string, std::string> city_facts;
    std::vector<EconomicSector> key_sectors;

public:
    JetpurInfoSystem() {
        city_facts["Location"] = "Rajkot district, Gujarat, India";
        city_facts["Population"] = "Approx. 120,000 (2023)";
        city_facts["Known For"] = "Hub for dyeing, printing, and textile industry, especially for cotton sarees and dress materials.";

        key_sectors.push_back({"Textile Printing", "Industry", "Jetpur is a major center for block printing and screen printing of textiles."});
        key_sectors.push_back({"Dyeing Units", "Industry", "Hundreds of small and large units specializing in fabric coloring and processing."});
        key_sectors.push_back({"Navagadh Fort", "Historical Landmark", "A local historical site near the town."});
    }

    void get_city_fact(const std::string& fact_name) const {
        if (city_facts.count(fact_name)) {
            std::cout << fact_name << ": " << city_facts.at(fact_name) << std::endl;
        } else {
            std::cout << "Fact not found: " << fact_name << std::endl;
        }
    }
    
    void search_sectors(const std::string& search_term) const {
        std::cout << "\n--- Search Results for '" << search_term << "' ---" << std::endl;
        bool found = false;
        std::string lower_search_term = search_term;
        // Convert search term to lowercase for case-insensitive search
        std::transform(lower_search_term.begin(), lower_search_term.end(), lower_search_term.begin(), ::tolower);

        for (const auto& sector : key_sectors) {
            std::string lower_name = sector.name;
            std::transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);
            
            if (lower_name.find(lower_search_term) != std::string::npos || 
                sector.type.find(search_term) != std::string::npos) {
                std::cout << "Name: " << sector.name << std::endl;
                std::cout << "Type: " << sector.type << std::endl;
                std::cout << "Description: " << sector.description << std::endl;
                std::cout << "----------------------------------------" << std::endl;
                found = true;
            }
        }
        if (!found) {
            std::cout << "No matching sectors or landmarks found." << std::endl;
        }
    }
};

int main() {
    JetpurInfoSystem info_system;
    
    // Display general facts
    info_system.get_city_fact("Location");
    info_system.get_city_fact("Known For");

    // Search for key economic sectors
    info_system.search_sectors("Industry");
    info_system.search_sectors("Fort");

    return 0;
}
