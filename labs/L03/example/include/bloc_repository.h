#ifndef BLOC_REPOSITORY_H
#define BLOC_REPOSITORY_H
#include "bloc.h"
#include <fstream>

class BlocRepository {
public:
    explicit BlocRepository(const std::string &source_file)
        : _sourceFile(source_file) {
        read();
    }

    const std::vector<Bloc>& getBlocuri();
    void modifyBloc(const Bloc &new_bloc);

private:
    std::string _sourceFile;
    std::vector<Bloc> _blocuri;

    void read();
    void save();
};

#endif //BLOC_REPOSITORY_H
