#include "BaseIngestor.hpp"
#include "seal/seal.h"

template <typename T>
class Re_encryption final : public BaseIngestor<T> {

private:
    seal::EncryptionParameters parms(seal::scheme_type::BFV);
    size_t poly_modulus_degree;

public:
    Re_encryption(const int & poly_mod_deg = 4096) : BaseIngestor<T>("Re_Encryption"), poly_modulus_degree(poly_mod_deg) {
        parms.set_poly_modulus_degree(poly_mod_deg);
        parms.set_coeff_modulus(seal::CoeffModulus::BFVDefault(poly_mod_deg));
        parms.set_plain_modulus(1024);
        auto context = SEALContext::Create(parms); 
        
    }

    ~Re_encryption();

    void setElement(const T & elem);
    bool isEmpty() const;
    T getElement();
};

template<typename T>
void Re_encryption<T>::setElement(const T & elem) {
    
    if(!IngestionQueue.write(elem)){
        std::cout << "not able to write" << std::endl;
        //TODO: log not able to write
        //fatal
    }
}