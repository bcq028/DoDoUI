#pragma once

namespace SlateAttributePrivate {

	template<typename InObjectType, typename InInvalidationReasonPredicate, typename InComparePredicate>
	struct TSlateMemberAttribute : public TSlateAttributeBase<SWidget, InObjectType, InInvalidationReasonPredicate, InComparePredicate, ESlateAttributeType::Member>
	{
	private:
		using Super = TSlateAttributeBase<SWidget, InObjectType, InInvalidationReasonPredicate, InComparePredicate, ESlateAttributeType::Member>;

	public:
		using FGetter = typename Super::FGetter;
		using ObjectType = typename Super::ObjectType;

		template<typename WidgetType, typename U = typename std::enable_if<std::is_base_of<SWidget, WidgetType>::value>::type>
		static void Verify_Attribute_Address(const WidgetType& widget, const TSlateMemberAttribute& self)
		{
			assert((uint64_t)&self >= (uint64_t)&widget && (uint64_t)&self < (uint64_t)&widget + sizeof(WidgetType));
		}

		TSlateMemberAttribute() = delete;

		TSlateMemberAttribute(const TSlateMemberAttribute&) = delete;

		TSlateMemberAttribute(TSlateMemberAttribute&&) = delete;

		TSlateMemberAttribute& operator=(const TSlateMemberAttribute&) = delete;

		TSlateMemberAttribute& operator=(TSlateMemberAttribute&&) = delete;

		void* operator new(size_t) = delete;

		void* operator new[](size_t) = delete;

		template<typename WidgetType, typename U = typename std::enable_if<std::is_base_of<SWidget, WidgetType>::value>::type>
		explicit TSlateMemberAttribute(WidgetType& widget)
			: Super(widget)
		{
			Verify_Attribute_Address(widget, *this);
		}

		template<typename WidgetType, typename U = typename std::enable_if<std::is_base_of<SWidget, WidgetType>::value>::type>
		explicit TSlateMemberAttribute(WidgetType& widget, const ObjectType& in_value)
			: Super(widget, in_value)
		{
			Verify_Attribute_Address(widget, *this);
		}
	};
}