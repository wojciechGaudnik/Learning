package single.dispatch;

import org.joda.money.CurrencyUnit;
import org.joda.money.Money;

public class AmountBasedDiscountPolicy  implements DiscountPolicy{
	@Override
	public double discount(Order order) {
		if (order.totalCost().isGreaterThan(Money.of(CurrencyUnit.USD, 500.00))) {
			return 0.10d;
		}
		return 0;
	}
}
