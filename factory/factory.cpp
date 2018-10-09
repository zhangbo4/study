//参考文档 https://www.cnblogs.com/cxjchen/p/3143633.html
#include <iostream>

//简单的工厂模式
// class AbstractProduct
// {
//     public:
//         virtual void getName() = 0;
// };
// class BMWProduct:public AbstractProduct
// {
//     public:
//         virtual void getName() 
//         {
//             std::cout << "I'm BMW product" << std::endl;
//         }
// };
// class AudiProduct:public AbstractProduct
// {
//     public:
//         virtual void getName() 
//         {
//             std::cout << "I'm Audi product" << std::endl;
//         }
// };

// class AbstractFactory
// {
//     public:
//         enum ProductTyep {
//             kBMW,
//             kAUDI
//         };

//         virtual AbstractProduct* createProduct(ProductTyep type) = 0;
// };
// class SimpleFactory:public AbstractFactory
// {
//     public:
//         virtual AbstractProduct* createProduct(ProductTyep type) 
//         {
//             switch(type) 
//             {
//                 case kBMW:
//                     return (new BMWProduct);
//                     break;
//                 case kAUDI:
//                     return (new AudiProduct);
//                     break;
//                 default:
//                     std::cout << "applaction err!!!" << std::endl;
//             }
//         }
// };

//工厂模式
// class AbstractProduct
// {
//     public:
//         virtual void getName() = 0;
// };
// class BMWProduct:public AbstractProduct
// {
//     public:
//         virtual void getName() 
//         {
//             std::cout << "I'm BMW product" << std::endl;
//         }
// };
// class AudiProduct:public AbstractProduct
// {
//     public:
//         virtual void getName() 
//         {
//             std::cout << "I'm Audi product" << std::endl;
//         }
// };

// class AbstractFactory
// {
//     public:
//         virtual AbstractProduct* createProduct() = 0;
// };
// class BMWFactory:public AbstractFactory
// {
//     public:
//         virtual AbstractProduct* createProduct()
//         {
//             return (new BMWProduct);
//         }
// };
// class AudiFactory:public AbstractFactory
// {
//     public:
//         virtual AbstractProduct* createProduct()
//         {
//             return (new AudiProduct);
//         }
// };

//抽象工厂模式
class CarAbstractProduct
{
    public:
        virtual void getName() = 0;
};
class BMWCarProduct:public CarAbstractProduct
{
    public:
        virtual void getName()
        {
            std::cout << "I'm BMW car product" << std::endl;
        }
};
class AudiCarProduct:public CarAbstractProduct
{
    public:
        virtual void getName()
        {
            std::cout << "I'm Audi car product" << std::endl;
        }
};

class BikeAbstractProduct
{
    public:
        virtual void getName() = 0;
};
class BMWBikeProduct:public BikeAbstractProduct
{
    public:
        virtual void getName()
        {
            std::cout << "I'm BMW bike product" << std::endl;
        }
};
class AudiBikeProduct:public BikeAbstractProduct
{
    public:
        virtual void getName()
        {
            std::cout << "I'm Audi bike product" << std::endl;
        }
};

class AbstractFactory 
{
    public:
        virtual CarAbstractProduct*  createCarProduct() = 0;
        virtual BikeAbstractProduct* createBikeProduct() = 0;
};
class Factory_1:public AbstractFactory
{
    public:
        virtual CarAbstractProduct* createCarProduct()
        {
            return (new BMWCarProduct);
        }

        virtual BikeAbstractProduct* createBikeProduct()
        {
            return (new BMWBikeProduct);
        }
};
class Factory_2:public AbstractFactory
{
    public:
        virtual CarAbstractProduct* createCarProduct()
        {
            return (new AudiCarProduct);
        }

        virtual BikeAbstractProduct* createBikeProduct()
        {
            return (new AudiBikeProduct);
        }
};

int main() 
{
    //简单的工厂模式
    // AbstractFactory* factory = new SimpleFactory();
    // AbstractProduct* productOne = factory->createProduct(AbstractFactory::kBMW);
    // productOne->getName();
    // delete productOne;

    // AbstractProduct* productTwo = factory->createProduct(AbstractFactory::kAUDI);
    // productTwo->getName();
    // delete productTwo;
    // delete factory;

    //工厂模式
    // AbstractFactory* factoryOne = new BMWFactory();
    // AbstractProduct* productOne = factoryOne->createProduct();
    // productOne->getName();
    // delete factoryOne;
    // delete productOne;

    // AbstractFactory* factoryTwo = new AudiFactory();
    // AbstractProduct* productTwo = factoryTwo->createProduct();
    // productTwo->getName();
    // delete factoryTwo;
    // delete productTwo;

    //抽象工厂模式
    Factory_1* factory1 = new Factory_1();
    CarAbstractProduct* carProductOne = factory1->createCarProduct();
    BikeAbstractProduct* bikeProductOne = factory1->createBikeProduct();
    carProductOne->getName();
    bikeProductOne->getName();
    delete factory1, carProductOne, bikeProductOne;

    Factory_2* factory2 = new Factory_2();
    CarAbstractProduct* carProductTwo = factory2->createCarProduct();
    BikeAbstractProduct* bikeProductTwo = factory2->createBikeProduct();
    carProductTwo->getName();
    bikeProductTwo->getName();
    delete factory2, carProductTwo, bikeProductTwo;

    return 0;
}
