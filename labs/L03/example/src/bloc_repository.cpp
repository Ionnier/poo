#include "../include/bloc_repository.h"

void BlocRepository::read() {
    std::ifstream f;
    f.open(_sourceFile);
    int n;
    f >> n;
    for (int i = 0; i < n; i++) {
        Bloc b;
        f >> b;
        _blocuri.push_back(b);
    }
    f.close();
}

void BlocRepository::save() {
    std::ofstream f;
    f.open(_sourceFile, std::ios::out | std::ios::trunc);
    f << _blocuri.size() << std::endl;
    for (auto &bloc: _blocuri) {
        f << bloc;
    }
    f.close();
}

const std::vector<Bloc> & BlocRepository::getBlocuri() {
    // in memory cache to prevent reading from the file all the time
    return _blocuri;
}

void BlocRepository::modifyBloc(const Bloc &new_bloc) {
    // this is a Lambda function (detailed later in the course)
    //   lambda functions allow passing functions in a more simpler way
    //   elements inside [] are local variables that are available inside the lambda function as well
    //   elements inside () are the elements with which the lambda function is called with
    //   the code inside {} is the function that is executed and returns the value needed
    erase_if(_blocuri, [new_bloc](const Bloc &bloc) {
       return bloc == new_bloc;
    });
    _blocuri.emplace_back(new_bloc);
    save();
}
