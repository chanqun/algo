# -*- coding: utf-8 -*-

class Company:
    def __init__(self, operation_profit, current_asset, current_liabilities, investment_assets,
                 fixed_debt, number_of_issued_shares, stock):
        # 영업 이익
        self.__operation_profit = operation_profit
        # 유동 자산
        self.__current_assets = current_asset
        # 유동 부채
        self.__current_liabilities = current_liabilities
        # 투자 자산
        self.__investment_assets = investment_assets
        # 고정 부채
        self.__fixed_debt = fixed_debt
        # 발행 주식 수
        self.number_of_issued_shares = number_of_issued_shares
        # 거래가
        self.stock = stock

    def summaryCompany(self):
        print("이 기업의 적정 주가는 {0} 현재 주가는 {1}".format(self.calcFairPrice(), self.stock))

    def calcFairPrice(self):
        return self.calcShareHolderValue() / self.number_of_issued_shares

    def calcShareHolderValue(self):
        return self.calcBusinessValue() + self.calcPropertyValue() - self.__fixed_debt

    def calcBusinessValue(self):
        return self.__operation_profit * 10

    def calcPropertyValue(self):
        return self.__current_assets - (1.2 * self.__current_liabilities) + self.__investment_assets


if __name__ == '__main__':
    sds = Company(
        int("990,089,397,088".replace(",", "")),
        int("6,383,846,734,777".replace(",", "")),
        int("1,698,187,475,543".replace(",", "")),
        int("99,432,086,938".replace(",", "")),
        int("597,891,318,411".replace(",", "")),
        77377800,
        132000
    )

    sds.summaryCompany()
